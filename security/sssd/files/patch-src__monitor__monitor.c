From 628c783aa78c576f10087e3e4812904b90d218b0 Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 04/34] patch-src__monitor__monitor.c

---
 src/monitor/monitor.c | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)

diff --git src/monitor/monitor.c src/monitor/monitor.c
index 8612524..3d3cab8 100644
--- src/monitor/monitor.c
+++ src/monitor/monitor.c
@@ -90,6 +90,11 @@ int cmdline_debug_level;
 int cmdline_debug_timestamps;
 int cmdline_debug_microseconds;
 
+errno_t monitor_config_file_fallback(TALLOC_CTX *mem_ctx,
+                                     struct mt_ctx *ctx,
+                                     const char *file,
+                                     monitor_reconf_fn fn,
+                                     bool ignore_missing);
 struct svc_spy;
 
 enum mt_svc_type {
@@ -1792,11 +1797,6 @@ done:
     talloc_free(tmp_ctx);
 }
 
-errno_t monitor_config_file_fallback(TALLOC_CTX *mem_ctx,
-                                     struct mt_ctx *ctx,
-                                     const char *file,
-                                     monitor_reconf_fn fn,
-                                     bool ignore_missing);
 static void rewatch_config_file(struct tevent_context *ev,
                                 struct tevent_timer *te,
                                 struct timeval t, void *ptr)
-- 
1.8.0

