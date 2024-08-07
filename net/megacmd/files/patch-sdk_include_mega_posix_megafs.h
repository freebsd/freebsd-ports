--- sdk/include/mega/posix/megafs.h.orig	2024-05-17 14:19:43 UTC
+++ sdk/include/mega/posix/megafs.h
@@ -32,7 +32,7 @@
 #define O_DIRECT 0
 #include <sys/param.h>
 #include <sys/mount.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/mount.h>
 #else
 #include <sys/vfs.h>
