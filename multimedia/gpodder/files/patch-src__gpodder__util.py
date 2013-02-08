--- ./src/gpodder/util.py.orig	2012-12-22 15:53:19.000000000 +0400
+++ ./src/gpodder/util.py	2013-01-16 15:18:56.000000000 +0400
@@ -1682,7 +1682,7 @@
         if gpodder.ui.win32:
             # FIXME: Implement for Windows
             return True
-        elif gpodder.ui.osx:
+        elif gpodder.ui.osx or 'freebsd' in sys.platform:
             return len(list(osx_get_active_interfaces())) > 0
             return True
         else:
