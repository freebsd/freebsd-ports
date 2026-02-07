--- catfish_lib/SudoDialog.py.orig	2020-01-01 17:46:05 UTC
+++ catfish_lib/SudoDialog.py
@@ -314,7 +314,11 @@ class SudoDialog(Gtk.Dialog):
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
