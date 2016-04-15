--- gtk/gui.c.orig	2016-04-06 10:39:35 UTC
+++ gtk/gui.c
@@ -199,7 +199,7 @@ static nserror set_defaults(struct nsopt
 	}
 
 	/* default path to certificates */
-	nsoption_setnull_charp(ca_path, strdup("/etc/ssl/certs"));
+	nsoption_setnull_charp(ca_path, strdup("%%PREFIX%%/share/certs"));
 
 	if ((nsoption_charp(cookie_file) == NULL) ||
 	    (nsoption_charp(cookie_jar) == NULL) ||
