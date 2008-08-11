--- Bundles/WildMenus/NSMenu+Hackery.m.orig	2005-12-01 00:55:35.000000000 +0100
+++ Bundles/WildMenus/NSMenu+Hackery.m	2008-08-11 10:15:32.000000000 +0200
@@ -27,6 +27,8 @@
 #include <AppKit/NSMenuView.h>
 #include <AppKit/NSWindow.h>
 
+#include <GNUstepGUI/GSVersion.h>
+
 #include "NSMenu+Hackery.h"
 
 @implementation NSMenu (HorizontalHackery)
@@ -35,7 +37,11 @@
 
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
