--- ./src/daemon/driver/driverMain.ml.orig	Sat Apr  8 21:26:40 2006
+++ ./src/daemon/driver/driverMain.ml	Mon May 15 13:03:12 2006
@@ -74,8 +74,8 @@
   CommonInteractive.force_download_quotas ();
   CommonResult.dummy_result.result_time <- last_time ();
   (try
-      CommonSwarming.verify_some_chunks ()
-    with _ -> ());
+    CommonSwarming.verify_some_chunks ()
+  with _ -> ());
   CommonClient.clear_upload_slots ()
 
 let hourly_timer timer =
