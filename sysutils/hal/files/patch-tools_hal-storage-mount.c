--- tools/hal-storage-mount.c.orig	2008-04-29 20:05:38.000000000 -0400
+++ tools/hal-storage-mount.c	2008-04-29 20:05:44.000000000 -0400
@@ -56,7 +56,7 @@
 
 #ifdef __FreeBSD__
 #define MOUNT		"/sbin/mount"
-#define MOUNT_OPTIONS	"noexec,nosuid"
+#define MOUNT_OPTIONS	"nosuid"
 #define MOUNT_TYPE_OPT	"-t"
 #elif sun
 #define MOUNT		"/sbin/mount"
