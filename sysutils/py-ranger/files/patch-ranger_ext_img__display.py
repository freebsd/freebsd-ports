Avoid hardcoded paths to w3mimgdisplay

--- ranger/ext/img_display.py.orig	2019-12-31 15:07:45 UTC
+++ ranger/ext/img_display.py
@@ -35,11 +35,7 @@ from ranger.core.shared import FileManagerAware
 W3MIMGDISPLAY_ENV = "W3MIMGDISPLAY_PATH"
 W3MIMGDISPLAY_OPTIONS = []
 W3MIMGDISPLAY_PATHS = [
-    '/usr/lib/w3m/w3mimgdisplay',
-    '/usr/libexec/w3m/w3mimgdisplay',
-    '/usr/lib64/w3m/w3mimgdisplay',
-    '/usr/libexec64/w3m/w3mimgdisplay',
-    '/usr/local/libexec/w3m/w3mimgdisplay',
+    '%%LOCALBASE%%/libexec/w3m/w3mimgdisplay',
 ]
 
 # Helper functions shared between the previewers (make them static methods of the base class?)
