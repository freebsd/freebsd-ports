commit 2fd0f94b4ea96bf3f67d53ebda4f40bc82711bb9
Author: Oleg Panashchenko <helg.git@helg.com>
Date:   Thu Apr 30 13:53:04 2015 -0400

    Fixed #486
    
    was a regression from 02bed4d

diff --git src/swl/swl_wincoreUX.cpp src/swl/swl_wincoreUX.cpp
index a161e24..7926b6a 100644
--- src/swl/swl_wincoreUX.cpp
+++ src/swl/swl_wincoreUX.cpp
@@ -1166,22 +1166,22 @@ static const char* getEventName(int id)
 				{
 					// close all popups
 					Win* w = GetWinByID( activeWinId );
-					//dbg_printf("FocusOut %s\n", typeid(*w).name());
-					while(w->parent)
-						w=w->parent;
-					ccollect<WinID> wl;
-					w->PopupTreeList( wl );
-					//dbg_printf("PopupTreeList size=%d\n",wl.count());
-					for(int i=0;i<wl.count();i++)
+					if( w ) 
 					{
-						Win* popup = GetWinByID( wl[i] );
-						if(popup)
+						while(w->parent)
+							w=w->parent;
+						ccollect<WinID> wl;
+						w->PopupTreeList( wl );
+						for(int i=0;i<wl.count();i++)
 						{
-							//dbg_printf("Closing %s\n", typeid(*w).name());
-							if(popup->parent)
-								popup->Parent()->Command( CMD_MENU_INFO, SCMD_MENU_CANCEL, popup, 0 );
+							Win* popup = GetWinByID( wl[i] );
+							if(popup)
+							{
+								if(popup->parent)
+									popup->Parent()->Command( CMD_MENU_INFO, SCMD_MENU_CANCEL, popup, 0 );
+							}
+							
 						}
-						
 					}
 				}
 
