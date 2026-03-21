--- spa/plugins/vulkan/vulkan-compute-utils.c.orig	2026-03-16 11:54:17 UTC
+++ spa/plugins/vulkan/vulkan-compute-utils.c
@@ -11,8 +11,10 @@
 #include <fcntl.h>
 #include <string.h>
 #include <vulkan/vulkan_core.h>
-#if !defined(__FreeBSD__) && !defined(__MidnightBSD__)
+#ifdef __linux__
 #include <alloca.h>
+#else
+#include <stdlib.h>
 #endif
 #include <errno.h>
 #include <stdio.h>
