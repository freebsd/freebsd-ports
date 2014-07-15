--- ./uget-gtk/UgSetting.c.orig	2014-01-01 09:39:00.000000000 +0000
+++ ./uget-gtk/UgSetting.c	2014-07-12 11:51:49.000000000 +0000
@@ -457,7 +457,7 @@
 	setting->window.statusbar = TRUE;
 	setting->window.category  = TRUE;
 	setting->window.summary   = TRUE;
-	setting->window.banner    = TRUE;
+	setting->window.banner    = FALSE;
 	setting->window.x = 0;
 	setting->window.y = 0;
 	setting->window.width = 0;
