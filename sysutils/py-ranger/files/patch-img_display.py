--- ranger/ext/img_display.py.orig	2014-02-05 11:33:29.000000000 +0800
+++ ranger/ext/img_display.py	2014-02-05 11:34:00.000000000 +0800
@@ -13,7 +13,7 @@
 import termios, fcntl, struct, sys, os
 from subprocess import Popen, PIPE
 
-W3MIMGDISPLAY_PATH = '/usr/lib/w3m/w3mimgdisplay'
+W3MIMGDISPLAY_PATH = '%%LOCALBASE%%/libexec/w3m/w3mimgdisplay'
 W3MIMGDISPLAY_OPTIONS = []
 
 class ImgDisplayUnsupportedException(Exception):
