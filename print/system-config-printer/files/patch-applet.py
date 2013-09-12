--- applet.py.orig	2013-07-22 15:58:32.000000000 +0200
+++ applet.py	2013-08-29 11:06:43.000000000 +0200
@@ -43,7 +43,7 @@
 
 from gi.repository import Notify
 
-APPDIR="/usr/share/system-config-printer"
+APPDIR="%%PREFIX%%/share/system-config-printer"
 ICON="printer"
 
 # We need to call Notify.init before we can check the server for caps
