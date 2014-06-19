--- src/buffer.cpp.orig	2010-02-15 13:08:46.000000000 +0000
+++ src/buffer.cpp
@@ -16,7 +16,7 @@
 
 #include <new>
 
-extern Buffer *Buffer::singleton = NULL;
+Buffer *Buffer::singleton = NULL;
 
 struct PreventBufferLeak
 {
