//==============================================================================
#include "CApp.h"
#include "CMap.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event)
{
    CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    switch(sym)
    {
    case SDLK_UP:
        CCamera::CameraControl.OnMove( 0,  CAMERA_SPEED);
        break;
    case SDLK_DOWN:
        CCamera::CameraControl.OnMove( 0, -CAMERA_SPEED);
        break;
    case SDLK_LEFT:
        CCamera::CameraControl.OnMove( CAMERA_SPEED,  0);
        break;
    case SDLK_RIGHT:
        CCamera::CameraControl.OnMove(-CAMERA_SPEED,  0);
        break;

    default:
    {
    }
    }
}

void CApp::OnLButtonDown(int mX, int mY)
{
    CTile* tile;
    int newTileID = 10;
    int newTypeID = 1;

    tile = CArea::AreaControl.GetTile(mX + CCamera::CameraControl.GetX(), mY + CCamera::CameraControl.GetY());

    CMap* Map;

    Map->SetTile(tile, newTileID, newTypeID);
}

void CApp::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
	if (Left)
	{
	    CTile* tile;
        int newTileID = 10;
        int newTypeID = 1;

        tile = CArea::AreaControl.GetTile(mX + CCamera::CameraControl.GetX(), mY + CCamera::CameraControl.GetY());

        CMap* Map;

        Map->SetTile(tile, newTileID, newTypeID);
	}
}

//------------------------------------------------------------------------------
void CApp::OnExit()
{
    Running = false;
}

//==============================================================================