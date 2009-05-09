--- ./printer-applet/printer-applet.py.orig	2008-10-09 13:46:28.000000000 +0400
+++ ./printer-applet/printer-applet.py	2009-05-04 21:25:37.000000000 +0400
@@ -36,7 +36,7 @@
 import subprocess
 import sys
 
-SYSTEM_CONFIG_PRINTER_DIR = "/usr/share/system-config-printer"
+SYSTEM_CONFIG_PRINTER_DIR = "%%LOCALBASE%%/share/system-config-printer"
 
 MIN_REFRESH_INTERVAL = 1 # seconds
 CONNECTING_TIMEOUT = 60 # seconds
