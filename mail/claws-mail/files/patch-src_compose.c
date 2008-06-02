--- src/compose.c	2008/04/30 06:46:01	1.382.2.446
+++ src/compose.c	2008/05/04 15:58:59	1.382.2.447
@@ -1591,7 +1591,7 @@
 
 		} else {
 			qmark = prefs_common.quotemark;
-			body_fmt = prefs_common.quotefmt;
+			body_fmt = gettext(prefs_common.quotefmt);
 		}
 	}
 
@@ -1746,7 +1746,7 @@
 		g_free(msgfile);
 	} else {
 		const gchar *qmark = NULL;
-		const gchar *body_fmt = prefs_common.fw_quotefmt;
+		const gchar *body_fmt = gettext(prefs_common.fw_quotefmt);
 		MsgInfo *full_msginfo;
 
 		full_msginfo = procmsg_msginfo_get_full_info(msginfo);
@@ -1767,7 +1767,7 @@
 
 		} else {
 			qmark = prefs_common.fw_quotemark;
-			body_fmt = prefs_common.fw_quotefmt;
+			body_fmt = gettext(prefs_common.fw_quotefmt);
 		}
 
 		/* empty quotemark is not allowed */
