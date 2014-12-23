--- Output/esd/mixer.c.orig	2006-07-16 13:40:04 UTC
+++ Output/esd/mixer.c
@@ -164,7 +164,8 @@ void esdout_set_volume(int l, int r)
 
 static void esdout_get_oss_volume(int *l, int *r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs;
+	long cmd;
 
 	if (esd_cfg.use_remote)
 		return;
@@ -191,7 +192,8 @@ static void esdout_get_oss_volume(int *l
 
 static void esdout_set_oss_volume(int l, int r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs;
+	long cmd;
 
 	if (esd_cfg.use_remote)
 		return;
