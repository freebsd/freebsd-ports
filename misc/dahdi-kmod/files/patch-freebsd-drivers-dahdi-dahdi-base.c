--- freebsd/drivers/dahdi/dahdi-base.c.orig	2013-10-31 17:36:56.000000000 +0700
+++ freebsd/drivers/dahdi/dahdi-base.c	2013-10-31 17:47:28.000000000 +0700
@@ -9206,7 +9263,9 @@
 	.d_poll		= dahdi_device_poll,
 	.d_mmap		= dahdi_device_mmap,
 	.d_name		= "dahdi",
-#if __FreeBSD_version >= 800039
+#if __FreeBSD_version >= 1000000
+	.d_flags	= D_TRACKCLOSE | D_NEEDMINOR,
+#elif __FreeBSD_version >= 800039
 	.d_flags	= D_PSEUDO | D_TRACKCLOSE | D_NEEDMINOR
 #else
 	.d_flags	= D_PSEUDO | D_TRACKCLOSE
