--- ./lib/src/libcommon.h.orig	2011-07-08 12:32:09.000000000 +0000
+++ ./lib/src/libcommon.h	2012-12-11 07:48:00.604014902 +0000
@@ -188,7 +188,7 @@
 }
 
 namespace zip {
-typedef ResourceWrapper<void, void*, int, gzclose> gzFile;
+typedef ResourceWrapper<struct gzFile_s, struct gzFile_s *, int, gzclose> gzFileWrapper;
 }
 
 /* Create a new temporary file. Return file name in file name encoding.
