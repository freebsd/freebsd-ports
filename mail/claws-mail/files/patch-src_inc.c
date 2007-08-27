--- src/inc.c.orig	2007-08-27 21:25:26.000000000 +0200
+++ src/inc.c	2007-08-27 21:25:54.000000000 +0200
@@ -1203,7 +1203,7 @@
 		mainwindow_show_error();
 
 	if (err_msg) {
-		alertpanel_error_log(err_msg);
+		alertpanel_error_log("%s", err_msg);
 		g_free(err_msg);
 	}
 }
