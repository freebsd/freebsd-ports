--- include/ogdf/basic/System.h.orig	2015-05-29 15:36:24 UTC
+++ include/ogdf/basic/System.h
@@ -53,7 +53,7 @@
 #define OGDF_SYSTEM_H
 
 
-#if defined(OGDF_SYSTEM_OSX)
+#if defined(OGDF_SYSTEM_OSX) || defined(OGDF_SYSTEM_FREEBSD)
 #include <stdlib.h>
 #elif defined(OGDF_SYSTEM_UNIX) || defined(__MINGW32__)
 #include <malloc.h>
@@ -176,7 +176,7 @@ public:
 	static void *alignedMemoryAlloc16(size_t size) {
 #ifdef OGDF_SYSTEM_WINDOWS
 		return _aligned_malloc(size, 16);
-#elif defined(OGDF_SYSTEM_OSX)
+#elif defined(OGDF_SYSTEM_OSX) || defined(OGDF_SYSTEM_FREEBSD)
 		// malloc returns 16 byte aligned memory on OS X.
 		return malloc(size);
 #else
