--- applet.py.orig	2009-12-22 09:44:19.000000000 -0500
+++ applet.py	2009-12-29 00:06:27.000000000 -0500
@@ -43,7 +43,7 @@
     os.environ['LC_ALL'] = 'C'
     locale.setlocale (locale.LC_ALL, "")
 
-APPDIR="/usr/share/system-config-printer"
+APPDIR="%%PREFIX%%/share/system-config-printer"
 DOMAIN="system-config-printer"
 ICON="printer"
 SEARCHING_ICON="document-print-preview"
@@ -234,7 +234,7 @@
         pid = os.fork ()
         if pid == 0:
             # Child.
-            cmd = "/usr/bin/system-config-printer"
+            cmd = "%%PREFIX%%/bin/system-config-printer"
             argv.insert (0, cmd)
             os.execvp (cmd, argv)
             sys.exit (1)
