--- SpaceTimeViewer/DrawView+Finding.m.orig	2006-10-29 20:52:48.000000000 +0100
+++ SpaceTimeViewer/DrawView+Finding.m	2012-01-14 08:09:36.000000000 +0100
@@ -24,7 +24,9 @@
 #include "DrawView.h"
 
 #include <math.h>
+#if !defined(__FreeBSD__)
 #include <values.h>
+#endif
 
 
 // returns a rectangle that is the same as rect but has positive height and width
