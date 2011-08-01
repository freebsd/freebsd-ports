--- mozilla/gfx/ycbcr/chromium_types.h.orig	2010-07-12 11:52:39.000000000 +0200
+++ mozilla/gfx/ycbcr/chromium_types.h	2010-07-12 11:53:21.000000000 +0200
@@ -72,6 +72,10 @@
 #define ARCH_CPU_SPARC_FAMILY 1
 #define ARCH_CPU_SPARC 1
 #define ARCH_CPU_64_BITS 1
+#elif defined(__sparc64__)
+#define ARCH_CPU_SPARC_FAMILY 1
+#define ARCH_CPU_SPARC 1
+#define ARCH_CPU_64_BITS 1
 #else
 #error Please add support for your architecture in chromium_types.h
 #endif
