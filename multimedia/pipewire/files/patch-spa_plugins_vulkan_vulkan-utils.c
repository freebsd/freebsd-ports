--- spa/plugins/vulkan/vulkan-utils.c.orig	2022-07-07 08:19:55 UTC
+++ spa/plugins/vulkan/vulkan-utils.c
@@ -6,7 +6,7 @@
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <string.h>
-#if defined(__FreeBSD__) || defined(__MidnightBSD__)
+#if !defined(__FreeBSD__) || defined(__MidnightBSD__)
 #include <alloca.h>
 #endif
 #include <errno.h>
