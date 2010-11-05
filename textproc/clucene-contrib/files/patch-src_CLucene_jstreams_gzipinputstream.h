--- src/CLucene/jstreams/gzipinputstream.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/gzipinputstream.h.orig	Fri Nov 24 13:42:02 2006
@@ -24,7 +24,8 @@
     bool checkMagic();
 public:
     enum ZipFormat { ZLIBFORMAT, GZIPFORMAT, ZIPFORMAT};
-    GZipInputStream(StreamBase<char>* input, ZipFormat format=GZIPFORMAT);
+    explicit GZipInputStream(StreamBase<char>* input,
+        ZipFormat format=GZIPFORMAT);
     ~GZipInputStream();
     int32_t fillBuffer(char* start, int32_t space);
 };
