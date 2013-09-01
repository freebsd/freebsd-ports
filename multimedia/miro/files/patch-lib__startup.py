--- lib/startup.py.orig	2013-08-17 02:48:00.884785831 +0000
+++ lib/startup.py	2013-08-17 02:48:27.966783822 +0000
@@ -501,8 +501,8 @@
     yield None
     commandline.startup()
     yield None
-    autoupdate.check_for_updates()
-    yield None
+    # autoupdate.check_for_updates()
+    # yield None
     app.local_metadata_manager.schedule_retry_net_lookup()
     # Delay running high CPU/IO operations for a bit
     eventloop.add_timeout(5, app.download_state_manager.startup_downloader,
