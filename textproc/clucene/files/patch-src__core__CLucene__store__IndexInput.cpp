--- src/core/CLucene/store/IndexInput.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/store/IndexInput.cpp	2014-06-24 18:38:50.000000000 -0400
@@ -41,8 +41,8 @@
   }
 
   int64_t IndexInput::readLong() {
-    int64_t i = ((int64_t)readInt() << 32);
-    return (i | ((int64_t)readInt() & 0xFFFFFFFFL));
+    uint64_t i = ((uint64_t)readInt() << 32);
+    return (i | ((uint64_t)readInt() & 0xFFFFFFFFL));
   }
 
   int64_t IndexInput::readVLong() {
