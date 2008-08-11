--- Bundles/EtoileWildMenus/NSMenu+Hackery.m.orig	2008-01-04 00:44:24.000000000 +0100
+++ Bundles/EtoileWildMenus/NSMenu+Hackery.m	2008-01-04 00:46:07.000000000 +0100
@@ -27,6 +27,8 @@
 #include <AppKit/NSMenuView.h>
 #include <AppKit/NSWindow.h>
 
+#include <GNUstepGUI/GSVersion.h>
+
 #include "NSMenu+Hackery.h"
 
 #import "MenuBarHeight.h"
@@ -47,7 +49,11 @@
 
 - (void) shiftOnScreen
 {
+#if (GNUSTEP_GUI_MINOR_VERSION < 13)
   NSWindow *theWindow = _transient ? _bWindow : _aWindow;
+#else
+  NSWindow *theWindow = _menu.transient ? _bWindow : _aWindow;
+#endif
   NSRect    frameRect = [theWindow frame];
   NSRect    screenRect = [[NSScreen mainScreen] frame];
   NSPoint   vector    = {0.0, 0.0};
@@ -103,7 +109,11 @@
 - (void) _rightMouseDisplay: (NSEvent*)theEvent 
 {
   // enable context menus to function
+#if (GNUSTEP_GUI_MINOR_VERSION < 13)
   if (_horizontal == NO && [(NSMenuView *) _view isHorizontal] == NO)
+#else
+  if (_menu.horizontal == NO && [(NSMenuView *) _view isHorizontal] == NO)
+#endif
     {
       [self displayTransient];
       [_view mouseDown: theEvent];
