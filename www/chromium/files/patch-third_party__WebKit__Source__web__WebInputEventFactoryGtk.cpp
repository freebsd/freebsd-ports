--- third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp.orig	2014-01-07 21:06:23.000000000 +0100
+++ third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp	2014-01-11 00:54:01.000000000 +0100
@@ -40,6 +40,8 @@
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
 
+#include <cstdlib>
+
 #include "wtf/Assertions.h"
 
 namespace {
@@ -65,8 +67,8 @@
                  "gtk-double-click-time", &doubleClickTime,
                  "gtk-double-click-distance", &doubleClickDistance, NULL);
     return (time - gLastClickTime) > doubleClickTime
-           || abs(x - gLastClickX) > doubleClickDistance
-           || abs(y - gLastClickY) > doubleClickDistance;
+           || std::abs(x - gLastClickX) > doubleClickDistance
+           || std::abs(y - gLastClickY) > doubleClickDistance;
 }
 
 void resetClickCountState()
