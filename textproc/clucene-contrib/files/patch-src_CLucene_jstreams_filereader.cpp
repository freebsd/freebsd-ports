--- src/CLucene/jstreams/filereader.cpp	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/filereader.cpp.orig	Sat Nov 25 11:03:58 2006
@@ -26,11 +26,6 @@
     return nread;
 }
 int64_t
-FileReader::mark(int32_t readlimit) {
-    int64_t mp = reader->mark(readlimit);
-    return mp;
-}
-int64_t
 FileReader::reset(int64_t newpos) {
     position = reader->reset(newpos);
     if (position < -1) {
