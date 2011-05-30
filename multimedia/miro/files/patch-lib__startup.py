--- ./lib/startup.py.orig	2011-05-25 00:30:12.000000000 +0200
+++ ./lib/startup.py	2011-05-25 17:53:57.000000000 +0200
@@ -407,8 +407,8 @@
     yield None
     commandline.startup()
     yield None
-    autoupdate.check_for_updates()
-    yield None
+    # autoupdate.check_for_updates()
+    # yield None
     # Delay running high CPU/IO operations for a bit
     eventloop.add_timeout(5, downloader.startup_downloader,
             "start downloader daemon")
