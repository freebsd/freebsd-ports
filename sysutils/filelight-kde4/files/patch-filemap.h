--- src/filemap.h.orig	Sat Aug 14 00:36:51 2004
+++ src/filemap.h	Sat Aug 14 00:37:29 2004
@@ -68,6 +68,8 @@
     double deltaRed, deltaGreen, deltaBlue;
 
     unsigned int MAP_2MARGIN;
+
+    friend class Segment;
 };
 
 
