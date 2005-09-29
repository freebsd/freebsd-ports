--- Output/esd/mixer.c.orig	Thu Sep 29 09:48:56 2005
+++ Output/esd/mixer.c	Thu Sep 29 09:49:25 2005
@@ -146,7 +146,8 @@
 
 static void esdout_get_oss_volume(int *l, int *r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs;
+	long cmd;
 
 	if (esd_cfg.use_remote)
 		return;
@@ -173,7 +174,8 @@
 
 static void esdout_set_oss_volume(int l, int r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs;
+	long cmd;
 
 	if (esd_cfg.use_remote)
 		return;
