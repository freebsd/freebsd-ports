--- lib/startup.py.orig	2010-10-24 14:40:03.000000000 +0200
+++ lib/startup.py	2010-10-24 14:40:38.000000000 +0200
@@ -370,7 +370,7 @@
     yield None
     commandline.startup()
     yield None
-    autoupdate.check_for_updates()
+    # autoupdate.check_for_updates()
     yield None
     # Wait a bit before starting the downloader daemon.  It can cause a bunch
     # of disk/CPU load, so try to avoid it slowing other stuff down.
