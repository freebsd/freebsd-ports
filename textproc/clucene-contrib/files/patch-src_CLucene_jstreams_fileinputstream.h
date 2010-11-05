--- src/CLucene/jstreams/fileinputstream.h	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/fileinputstream.h.orig	Fri Nov 24 13:42:02 2006
@@ -18,7 +18,8 @@
 
 public:
     static const int32_t defaultBufferSize;
-    FileInputStream(const char *filepath, int32_t buffersize=defaultBufferSize);
+    explicit FileInputStream(const char *filepath,
+        int32_t buffersize=defaultBufferSize);
     ~FileInputStream();
     int32_t fillBuffer(char* start, int32_t space);
 };
