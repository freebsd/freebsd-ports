--- Output/OSS/mixer.c.orig	Thu Sep 29 09:46:32 2005
+++ Output/OSS/mixer.c	Thu Sep 29 09:47:14 2005
@@ -34,7 +34,8 @@
 
 void oss_get_volume(int *l, int *r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs;
+	long cmd;
 	gchar *devname;
 
 	devname = get_mixer_device();
@@ -66,7 +67,8 @@
 
 void oss_set_volume(int l, int r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs;
+	long cmd;
 	gchar *devname;
 
 	devname = get_mixer_device();
