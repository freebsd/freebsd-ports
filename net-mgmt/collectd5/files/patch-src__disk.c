--- src/disk.c.orig	2017-01-23 07:53:57 UTC
+++ src/disk.c
@@ -229,7 +229,7 @@ static int disk_init(void) {
     return (-1);
   }
   rv = geom_stats_open();
-  if (rv != 0) {
+  if (rv != 0 && rv != EBUSY) {
     ERROR("geom_stats_open() failed, returned %d", rv);
     return (-1);
   }
@@ -265,6 +265,9 @@ static int disk_shutdown(void) {
     udev_unref(handle_udev);
 #endif /* HAVE_LIBUDEV */
 #endif /* KERNEL_LINUX */
+#if KERNEL_FREEBSD
+  geom_stats_close();
+#endif /* KERNEL_FREEBSD */
   return (0);
 } /* int disk_shutdown */
 
