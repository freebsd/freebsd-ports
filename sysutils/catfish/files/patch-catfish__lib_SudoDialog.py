--- catfish_lib/SudoDialog.py.orig	2019-07-27 11:21:22 UTC
+++ catfish_lib/SudoDialog.py
@@ -18,6 +18,7 @@
 
 from gi.repository import Gtk, GdkPixbuf
 import os
+import sys
 
 from locale import gettext as _
 
@@ -316,7 +317,11 @@ class SudoDialog(Gtk.Dialog):
         Return True if successful.
         '''
         # Set the pexpect variables and spawn the process.
-        child = env_spawn('sudo /bin/true', 1)
+        if sys.platform.startswith('linux'):
+            child = env_spawn('sudo /bin/true', 1)
+        elif 'bsd' in sys.platform or sys.platform.startswith('dragonfly'):
+            child = env_spawn('sudo /usr/bin/true', 1)
+
         try:
             # Check for password prompt or program exit.
             child.expect([".*ssword.*", pexpect.EOF])
