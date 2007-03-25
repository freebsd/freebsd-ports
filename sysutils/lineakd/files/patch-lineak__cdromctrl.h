--- lineak/cdromctrl.h.orig	Mon Mar 19 22:21:01 2007
+++ lineak/cdromctrl.h	Mon Mar 19 22:21:10 2007
@@ -28,7 +28,7 @@
 #  define DEFAULT_CDROM_DEVICE "/dev/cdrom"
 #endif
 #if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
-#  define DEFAULT_CDROM_DEVICE "/dev/cd0c"
+#  define DEFAULT_CDROM_DEVICE "/dev/cd0"
 #endif
 #if defined (__CYGWIN__)
 #  define DEFAULT_CDROM_DEVICE "D:"
