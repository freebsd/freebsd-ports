--- core/objects/containers/BasicAllocators.h.orig	2024-10-15 17:04:09 UTC
+++ core/objects/containers/BasicAllocators.h
@@ -6,7 +6,9 @@
 /// \date 2016-2021
 
 #include "common/Assert.h"
-#ifndef SPH_WIN
+#if defined(__arm__) || defined(__aarch64__)
+#include <sse2neon.h>
+#elif !defined(SPH_WIN)
 #include <mm_malloc.h>
 #else
 #include <malloc.h>
