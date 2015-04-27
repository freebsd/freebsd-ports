--- third_party/skia/src/core/SkVarAlloc.cpp.orig	2015-04-19 19:15:20.000000000 +0200
+++ third_party/skia/src/core/SkVarAlloc.cpp	2015-04-19 19:17:08.000000000 +0200
@@ -4,7 +4,12 @@
 #if defined(SK_BUILD_FOR_MAC)
     #include <malloc/malloc.h>
 #elif defined(SK_BUILD_FOR_UNIX) || defined(SK_BUILD_FOR_WIN32)
+#  if defined(__FreeBSD__)
+    #include <stdlib.h>
+    #include <malloc_np.h>
+#  else
     #include <malloc.h>
+#  endif
 #endif
 
 struct SkVarAlloc::Block {
