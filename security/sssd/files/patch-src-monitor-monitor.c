Backport a887e33fbd from upstream:
MONITOR: Do not use two configuration databases

--- src/monitor/monitor.c.orig	2014-09-17 13:01:37 UTC
+++ src/monitor/monitor.c
@@ -2832,6 +2832,20 @@ int main(int argc, const char *argv[])
     ret = server_setup(MONITOR_NAME, flags, monitor->conf_path, &main_ctx);
     if (ret != EOK) return 2;
 
+    /* Use confd initialized in server_setup. ldb_tdb module (1.4.0) check PID
+    * of process which initialized db for locking purposes.
+    * Failed to unlock db: ../ldb_tdb/ldb_tdb.c:147:
+    *    Reusing ldb opened by pid 28889 in process 28893
+    */
+    talloc_zfree(monitor->cdb);
+    monitor->cdb = main_ctx->confdb_ctx;
+
+    ret = confdb_get_domains(monitor->cdb, &monitor->domains);
+    if (ret != EOK) {
+	     DEBUG(SSSDBG_FATAL_FAILURE, "No domains configured.\n");
+	     return 4;
+    }
+
     monitor->is_daemon = !opt_interactive;
     monitor->parent_pid = main_ctx->parent_pid;
     monitor->ev = main_ctx->event_ctx;
