--- ogdf/basic/System.h.orig	2012-07-18 09:17:51.000000000 +0200
+++ ogdf/basic/System.h	2013-06-18 10:23:07.000000000 +0200
@@ -51,7 +51,7 @@
 
 
 #include <ogdf/basic/basic.h>
-#if defined(OGDF_SYSTEM_OSX)
+#if defined(OGDF_SYSTEM_OSX) || defined(OGDF_SYSTEM_FREEBSD)
 #include <stdlib.h>
 #elif defined(OGDF_SYSTEM_UNIX) || defined(__MINGW32__)
 #include <malloc.h>
@@ -178,7 +178,7 @@
 		size_t alignment = 16;
 #ifdef OGDF_SYSTEM_WINDOWS
 		return _aligned_malloc(size,alignment);
-#elif defined(OGDF_SYSTEM_OSX)
+#elif defined(OGDF_SYSTEM_OSX) || defined(OGDF_SYSTEM_FREEBSD)
 		// malloc returns 16 byte aligned memory on OS X.
 		return malloc(size);
 #else
