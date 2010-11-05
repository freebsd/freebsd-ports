--- src/CLucene/jstreams/fileinputstream.cpp	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/fileinputstream.cpp.orig	Fri Nov 24 13:42:02 2006
@@ -12,7 +12,6 @@
 
 const int32_t FileInputStream::defaultBufferSize = 1048576;
 FileInputStream::FileInputStream(const char *filepath, int32_t buffersize) {
-
     // try to open the file for reading
     file = fopen(filepath, "rb");
     this->filepath = filepath;
@@ -21,7 +20,7 @@
         error = "Could not read file '";
         error += filepath;
         error += "': ";
-	error += strerror(errno);
+        error += strerror(errno);
         status = Error;
         return;
     }
@@ -47,7 +46,8 @@
     }
 
     // allocate memory in the buffer
-    mark(buffersize);
+    int32_t bufsize = (size <= buffersize) ?size+1 :buffersize;
+    mark(bufsize);
 }
 FileInputStream::~FileInputStream() {
     if (file) {
