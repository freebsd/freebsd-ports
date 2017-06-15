--- frontends/gtk/gui.c.orig	2016-11-19 13:37:41 UTC
+++ frontends/gtk/gui.c
@@ -198,7 +198,7 @@ static nserror set_defaults(struct nsopt
 	}
 
 	/* default path to certificates */
-	nsoption_setnull_charp(ca_path, strdup("/etc/ssl/certs"));
+	nsoption_setnull_charp(ca_path, strdup("%%PREFIX%%/share/certs"));
 
 	if ((nsoption_charp(cookie_file) == NULL) ||
 	    (nsoption_charp(cookie_jar) == NULL) ||
