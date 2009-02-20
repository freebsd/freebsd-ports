--- portable/startup.py.orig	2009-02-12 06:37:23.000000000 +0900
+++ portable/startup.py	2009-02-12 18:25:40.000000000 +0900
@@ -250,7 +250,7 @@
     yield None
     parse_command_line_args()
     yield None
-    autoupdate.check_for_updates()
+    # autoupdate.check_for_updates()
     yield None
     # Wait a bit before starting the downloader daemon.  It can cause a bunch
     # of disk/CPU load, so try to avoid it slowing other stuff down.
