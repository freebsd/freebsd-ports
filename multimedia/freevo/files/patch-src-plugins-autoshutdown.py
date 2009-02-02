--- src/plugins/autoshutdown.py.orig	2008-03-22 07:42:02.000000000 -0400
+++ src/plugins/autoshutdown.py	2009-01-13 21:39:21.000000000 -0500
@@ -632,7 +632,7 @@
     @returns: True/False
     """
     _debug_('__is_recordserver_remote()', 2)
-    if len(glob.glob('/var/run/recordserver*.pid')) > 0:
+    if len(glob.glob('/var/run/freevo/recordserver*.pid')) > 0:
         return False
     elif len(glob.glob('/tmp/recordserver*.pid')) > 0:
         return False
