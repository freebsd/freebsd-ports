--- SpaceTimeViewer/DrawView+Drawing.m.orig	Mon Jan  9 02:13:30 2006
+++ SpaceTimeViewer/DrawView+Drawing.m
@@ -23,7 +23,11 @@
 
 #include "DrawView.h"
 #ifdef GNUSTEP
+#  if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <values.h>
+#  else
+#include <math.h>
+#  endif
 #endif
 
 @implementation DrawView (Drawing)
