--- sdk/include/mega/posix/megasys.h.orig	2024-05-17 14:19:43 UTC
+++ sdk/include/mega/posix/megasys.h
@@ -99,7 +99,8 @@
 #include <endian.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__minix)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) || defined(__minix) || \
+    defined(__OpenBSD__)
 #include <sys/endian.h>
 #endif
 
