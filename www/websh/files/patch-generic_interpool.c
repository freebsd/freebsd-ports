--- ../generic/interpool.c.orig	2013-02-05 13:59:15.000000000 +0100
+++ ../generic/interpool.c	2013-02-05 14:00:59.000000000 +0100
@@ -573,7 +573,7 @@
 			  Tcl_GetStringResult(conf->mainInterp));
 #else /* APACHE2 */
 	    ap_log_error(APLOG_MARK, APLOG_NOERRNO | APLOG_ERR, 0,
-			 conf->server, Tcl_GetStringResult(conf->mainInterp));
+			 conf->server, "%s", Tcl_GetStringResult(conf->mainInterp));
 #endif /* APACHE2 */
 	    return 0;
 	}
