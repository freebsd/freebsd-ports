--- SpaceTimeViewer/DrawView+Drawing.m.orig	Mon Jan  9 02:13:30 2006
+++ SpaceTimeViewer/DrawView+Drawing.m	Thu Sep 28 20:56:39 2006
@@ -23,7 +23,11 @@
 
 #include "DrawView.h"
 #ifdef GNUSTEP
+#ifndef __FreeBSD__
 #include <values.h>
+#else
+#include <math.h>
+#endif
 #endif
 
 @implementation DrawView (Drawing)
