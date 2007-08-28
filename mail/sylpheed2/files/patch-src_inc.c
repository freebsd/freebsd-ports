Index: inc.c
===================================================================
--- src/inc.c	(revision 1874)
+++ src/inc.c	(revision 1880)
@@ -1364,7 +1364,7 @@
 			log_warning("%s\n", log_msg);
 	}
 	if (err_msg) {
-		alertpanel_error(err_msg);
+		alertpanel_error("%s", err_msg);
 		g_free(err_msg);
 	}
 }
