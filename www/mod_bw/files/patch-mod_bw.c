--- mod_bw.c.orig	Mon Apr 24 03:10:44 2006
+++ mod_bw.c	Tue May 16 14:01:56 2006
@@ -51,6 +51,14 @@
 #include "http_core.h"
 #include "scoreboard.h"
 
+#if APR_MAJOR_VERSION == 0
+#define	apr_atomic_set32(mem,val)	(atomic_set_32(mem,val),mem)
+#define	apr_atomic_inc32(mem)		(atomic_add_32(mem,1),mem)
+#define	apr_atomic_dec32(mem)		(atomic_subtract_32(mem,1),mem)
+#define	apr_atomic_add32(mem,val)	(atomic_add_32(mem,val),mem)
+#define apr_atomic_cas32		apr_atomic_cas
+#endif
+
 #define MIN_BW 256              /* Minimal bandwidth 256 bytes  */
 #define PACKET 8192             /* Default packet at 8192 bytes */
 
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
