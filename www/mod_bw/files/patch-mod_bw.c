--- mod_bw.c.orig	Mon Apr 24 03:10:44 2006
+++ mod_bw.c	Tue May 16 14:01:56 2006
@@ -715,8 +723,10 @@
 
         /* If we are too busy, deny connection */
         confid = get_maxconn(r, conf->maxconnection);
-        if ((bwstat->connection_count >= confid) && (confid > 0))
+        if ((bwstat->connection_count >= confid) && (confid > 0)) {
+	    ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server, "exceed lmit (error=%d, count=%d, confid=%d)", conf->error, bwstat->connection_count, confid);
             return conf->error;
+	}
     }
 
     /* Add the Filter, if in forced mode */
@@ -810,7 +820,7 @@
 
     /* Verbose Output */
     ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
-                 "ID: %ld Directory : %s Rate : %ld Minimum : %ld Size rate : %ld",
+                 "ID: %d Directory : %s Rate : %ld Minimum : %ld Size rate : %ld",
                  confid, conf->directory, bw_rate, bw_min, bw_f_rate);
     ap_log_error(APLOG_MARK, APLOG_DEBUG, 0, r->server,
                  "clients : %d/%d  rate/min : %ld,%ld", bwmaxconn->connection_count,
