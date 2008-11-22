--- applet.py.orig	2008-11-21 10:58:21.000000000 -0600
+++ applet.py	2008-11-22 11:28:38.936928214 -0600
@@ -43,7 +43,7 @@
     os.environ['LC_ALL'] = 'C'
     locale.setlocale (locale.LC_ALL, "")
 
-APPDIR="/usr/share/system-config-printer"
+APPDIR="%%PREFIX%%/share/system-config-printer"
 DOMAIN="system-config-printer"
 GLADE="applet.glade"
 ICON="printer"
@@ -61,7 +61,7 @@
     STATUS_GENERIC_DRIVER = 2
     STATUS_NO_DRIVER = 3
 
-    INSTALL_PACKAGES_COMMAND="/usr/bin/gpk-install-package-name"
+    INSTALL_PACKAGES_COMMAND="/usr/bin/true"
 
     def __init__ (self, bus):
         self.bus = bus
@@ -173,7 +173,7 @@
         pid = os.fork ()
         if pid == 0:
             # Child.
-            cmd = "/usr/bin/system-config-printer"
+            cmd = "%%PREFIX%%/bin/system-config-printer"
             argv.insert (0, cmd)
             os.execvp (cmd, argv)
             sys.exit (1)
