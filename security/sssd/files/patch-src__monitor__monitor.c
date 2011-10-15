--- ./src/monitor/monitor.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/monitor/monitor.c	2011-10-13 12:15:03.000000000 -0400
@@ -57,6 +57,10 @@
 
 int cmdline_debug_level;
 
+errno_t monitor_config_file_fallback(TALLOC_CTX *mem_ctx,
+                                     struct mt_ctx *ctx,
+                                     const char *file,
+                                     monitor_reconf_fn fn);
 struct svc_spy;
 
 struct mt_svc {
@@ -1606,10 +1610,6 @@
     talloc_free(tmp_ctx);
 }
 
-errno_t monitor_config_file_fallback(TALLOC_CTX *mem_ctx,
-                                     struct mt_ctx *ctx,
-                                     const char *file,
-                                     monitor_reconf_fn fn);
 static void rewatch_config_file(struct tevent_context *ev,
                                 struct tevent_timer *te,
                                 struct timeval t, void *ptr)
