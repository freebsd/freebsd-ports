--- SpaceTimeViewer/DrawView+Drawing.m.orig	2007-02-16 13:23:30 UTC
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
 
 #include "../General/Association.h"
