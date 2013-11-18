--- third_party/WebKit/Source/web/gtk/WebInputEventFactory.cpp.orig	2013-11-08 07:50:07.000000000 +0100
+++ third_party/WebKit/Source/web/gtk/WebInputEventFactory.cpp	2013-11-15 19:38:46.000000000 +0100
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
