--- ./lib/src/libcommon.h.orig	2012-01-13 06:21:34.000000000 +0000
+++ ./lib/src/libcommon.h	2013-10-02 15:13:21.563936478 +0000
@@ -188,7 +188,11 @@
 }
 
 namespace zip {
+#if ZLIB_VERNUM > 0x1250
+typedef ResourceWrapper<gzFile_s, gzFile, int, gzclose> gzFile;
+#else
 typedef ResourceWrapper<void, void*, int, gzclose> gzFile;
+#endif
 }
 
 /* Create a new temporary file. Return file name in file name encoding.
