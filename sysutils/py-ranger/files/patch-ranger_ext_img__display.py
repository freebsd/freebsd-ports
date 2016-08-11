--- ranger/ext/img_display.py.orig	2015-10-03 23:46:45 UTC
+++ ranger/ext/img_display.py
@@ -21,7 +21,7 @@ import termios
 from ranger.core.shared import FileManagerAware
 from subprocess import Popen, PIPE
 
-W3MIMGDISPLAY_PATH = '/usr/lib/w3m/w3mimgdisplay'
+W3MIMGDISPLAY_PATH = '%%LOCALBASE%%/libexec/w3m/w3mimgdisplay'
 W3MIMGDISPLAY_OPTIONS = []
 
 class ImgDisplayUnsupportedException(Exception):
