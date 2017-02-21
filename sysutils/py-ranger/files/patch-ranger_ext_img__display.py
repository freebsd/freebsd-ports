--- ranger/ext/img_display.py.orig	2017-02-20 16:56:49.277878000 +0800
+++ ranger/ext/img_display.py	2017-02-20 17:00:01.700857000 +0800
@@ -25,6 +25,7 @@
 W3MIMGDISPLAY_ENV = "W3MIMGDISPLAY_PATH"
 W3MIMGDISPLAY_OPTIONS = []
 W3MIMGDISPLAY_PATHS = [
+    '%%LOCALBASE%%/libexec/w3m/w3mimgdisplay',
     '/usr/lib/w3m/w3mimgdisplay',
     '/usr/libexec/w3m/w3mimgdisplay',
     '/usr/lib64/w3m/w3mimgdisplay',
