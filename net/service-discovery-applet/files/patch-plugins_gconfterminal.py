--- plugins/gconfterminal.py.orig	Sat May  6 18:53:01 2006
+++ plugins/gconfterminal.py	Sat May  6 18:53:10 2006
@@ -16,7 +16,7 @@ from sdapplet.pluginutils import *
 
 try:
     import gettext
-    gettext.bindtextdomain("service-discovery-applet", "/usr/share/locale")
+    gettext.bindtextdomain("service-discovery-applet", "%%PREFIX%%/share/locale")
     gettext.textdomain("service-discovery-applet")
     _ = gettext.gettext
     import pygtk
