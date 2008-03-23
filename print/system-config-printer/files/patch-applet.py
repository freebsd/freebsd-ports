--- applet.py.orig	2008-03-20 11:46:28.000000000 -0400
+++ applet.py	2008-03-20 11:48:47.000000000 -0400
@@ -22,7 +22,7 @@
 import statereason
 from statereason import StateReason
 
-APPDIR="/usr/share/system-config-printer"
+APPDIR="%%PREFIX%%/share/system-config-printer"
 DOMAIN="system-config-printer"
 GLADE="applet.glade"
 ICON="printer"
@@ -976,7 +976,7 @@
         pid = os.fork ()
         if pid == 0:
             # Child.
-            cmd = "/usr/bin/system-config-printer"
+            cmd = "%%PREFIX%%/sbin/system-config-printer"
             argv.insert (0, cmd)
             os.execvp (cmd, argv)
             sys.exit (1)
@@ -994,7 +994,7 @@
         pid = os.fork ()
         if pid == 0:
             # Child.
-            argv = ["/usr/bin/system-install-packages"]
+            argv = ["/usr/bin/true"]
             argv.extend (missing_pkgs)
             os.execv (argv[0], argv)
             sys.exit (1)
