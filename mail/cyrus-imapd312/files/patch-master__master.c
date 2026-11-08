--- master/master.c.orig	2026-09-09 01:06:41 UTC
+++ master/master.c
@@ -744,6 +744,9 @@ static int decode_wait_status(struct centry *c, pid_t 
         else if (WEXITSTATUS(status) == EX_TEMPFAIL) {
             syslog(LOG_DEBUG, "%s was killed", desc);
         }
+        else if (WEXITSTATUS(status) == EX_PROTOCOL) {
+            syslog(LOG_DEBUG, "%s exited due to protocol error", desc);
+        }
         else {
             syslog(LOG_ERR, "%s exited, status %d",
                    desc, WEXITSTATUS(status));
