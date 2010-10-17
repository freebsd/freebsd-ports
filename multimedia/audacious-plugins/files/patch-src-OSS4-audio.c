--- src/oss4/oss.c.orig	2010-09-09 13:56:41.000000000 +0200
+++ src/oss4/oss.c	2010-09-09 13:56:50.000000000 +0200
@@ -212,7 +212,7 @@
         {
             ERROR_MSG;
 
-            if (ioctl(oss_data->fd, SNDCTL_DSP_SYNC, NULL) == -1)
+            if (ioctl(oss_data->fd, SNDCTL_DSP_RESET, NULL) == -1)
                 DEBUG_MSG;
 
             break;
