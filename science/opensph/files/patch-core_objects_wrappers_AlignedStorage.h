--- core/objects/wrappers/AlignedStorage.h.orig	2024-10-15 17:05:35 UTC
+++ core/objects/wrappers/AlignedStorage.h
@@ -7,7 +7,9 @@
 
 #include "common/Assert.h"
 #include "common/Traits.h"
-#ifndef SPH_WIN
+#if defined(__arm__) || defined(__aarch64__)
+#include <sse2neon.h>
+#elif !defined(SPH_WIN)
 #include <mm_malloc.h>
 #else
 #include <malloc.h>
