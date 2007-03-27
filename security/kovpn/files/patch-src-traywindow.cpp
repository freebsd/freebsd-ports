--- src/traywindow.cpp	Mon Mar 26 10:41:03 2007
+++ src/traywindow.cpp	Mon Mar 26 10:41:27 2007
@@ -116,7 +116,7 @@
    delete mDisconnectMenuItems[ manager->id() ];
 
    /* I think (int) manager is unique and static enough to be used as id for the menu */
-   mContextMenu->removeItem( ( int ) manager );
+   mContextMenu->removeItem( ( size_t ) manager );
    mManagerMenus.remove( manager->id() );
    mOvpnManagers.remove( manager );
 }
@@ -134,7 +134,7 @@
 
    mManagerMenus[ manager->id() ] = new KPopupMenu( mContextMenu );
    /* I think (int) manager is unique and static enough to be used as id for the menu */
-   mContextMenu->insertItem( manager->id() , mManagerMenus[ manager->id() ] , ( int ) manager, 5 );
+   mContextMenu->insertItem( manager->id() , mManagerMenus[ manager->id() ] , ( size_t ) manager, 5 );
 
    mManagerMenus[ manager->id() ] ->insertTitle( i18n( "Status: Unavailable" ), 0 );
 
