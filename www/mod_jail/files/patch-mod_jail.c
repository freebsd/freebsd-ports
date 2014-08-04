--- ./mod_jail.c.orig	2014-07-29 18:28:40.000000000 -0400
+++ ./mod_jail.c	2014-07-29 18:28:56.000000000 -0400
@@ -336,12 +336,12 @@
 	if (geteuid()) {
 	    ap_log_error(APLOG_MARK, APLOG_ALERT, 0, s,
 			"mod_jail can't jail when not started as root.");
-	    return;
+	    return !OK;
 	}
 	if (chdir(cfg->jail.path) == -1) {
 	    ap_log_error(APLOG_MARK, APLOG_ERR, 0, s,
     		     "mod_jail unable to chdir to %s.", cfg->jail.path);
-    	    return;
+    	    return !OK;
 	}
         if (jail(&cfg->jail) == -1) {
             ap_log_error(APLOG_MARK, APLOG_ERR, 0, s,
