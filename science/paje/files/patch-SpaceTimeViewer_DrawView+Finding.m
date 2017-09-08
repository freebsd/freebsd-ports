--- SpaceTimeViewer/DrawView+Finding.m.orig	2006-10-29 19:52:48 UTC
+++ SpaceTimeViewer/DrawView+Finding.m
@@ -24,7 +24,9 @@
 #include "DrawView.h"
 
 #include <math.h>
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <values.h>
+#endif
 
 
 // returns a rectangle that is the same as rect but has positive height and width
