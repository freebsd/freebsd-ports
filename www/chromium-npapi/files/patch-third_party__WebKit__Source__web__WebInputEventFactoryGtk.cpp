--- ./third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp.orig	2014-04-30 22:47:14.000000000 +0200
+++ ./third_party/WebKit/Source/web/WebInputEventFactoryGtk.cpp	2014-05-04 14:38:48.000000000 +0200
@@ -41,6 +41,8 @@
 #include <gtk/gtk.h>
 #include <stdlib.h>
 
+#include <cstdlib>
+
 #include "wtf/Assertions.h"
 
 namespace {
@@ -66,8 +68,8 @@
                  "gtk-double-click-time", &doubleClickTime,
                  "gtk-double-click-distance", &doubleClickDistance, NULL);
     return (time - gLastClickTime) > doubleClickTime
-           || abs(x - gLastClickX) > doubleClickDistance
-           || abs(y - gLastClickY) > doubleClickDistance;
+           || std::abs(x - gLastClickX) > doubleClickDistance
+           || std::abs(y - gLastClickY) > doubleClickDistance;
 }
 
 void resetClickCountState()
