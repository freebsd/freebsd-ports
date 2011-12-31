--- src/oss4/oss.c.orig	2011-11-08 17:38:49.000000000 +0100
+++ src/oss4/oss.c	2011-11-24 11:26:36.000000000 +0100
@@ -191,7 +191,7 @@
 {
     AUDDBG("Drain.\n");
 
-    if (ioctl(oss_data->fd, SNDCTL_DSP_SYNC, NULL) == -1)
+    if (ioctl(oss_data->fd, SNDCTL_DSP_RESET, NULL) == -1)
         DESCRIBE_ERROR;
 }
 
