--- ui-gtk/UgtkSetting.c.orig	2015-04-30 23:37:53 UTC
+++ ui-gtk/UgtkSetting.c
@@ -334,7 +334,7 @@ void  ugtk_setting_reset (UgtkSetting* s
 	setting->window.statusbar = TRUE;
 	setting->window.category  = TRUE;
 	setting->window.summary   = TRUE;
-	setting->window.banner    = TRUE;
+	setting->window.banner    = FALSE;
 	setting->window.x = 0;
 	setting->window.y = 0;
 	setting->window.width = 0;
