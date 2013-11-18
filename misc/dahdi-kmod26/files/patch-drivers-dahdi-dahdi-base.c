--- drivers/dahdi/dahdi-base.c.orig	2013-11-18 19:11:51.000000000 +0700
+++ drivers/dahdi/dahdi-base.c	2013-11-18 19:12:07.000000000 +0700
@@ -10224,6 +10224,8 @@
 	.d_poll		= dahdi_device_poll,
 	.d_name		= "dahdi",
 #if __FreeBSD_version >= 800039
+	.d_flags	= D_TRACKCLOSE | D_NEEDMINOR
+#elif __FreeBSD_version >= 800039
 	.d_flags	= D_PSEUDO | D_TRACKCLOSE | D_NEEDMINOR
 #else
 	.d_flags	= D_PSEUDO | D_TRACKCLOSE
