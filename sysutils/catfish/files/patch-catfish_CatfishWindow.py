--- catfish/CatfishWindow.py.orig	2020-01-01 18:26:21 UTC
+++ catfish/CatfishWindow.py
@@ -822,9 +822,15 @@ class CatfishWindow(Window):
         self.update_index_unlock.set_sensitive(False)
 
         if SudoDialog.prefer_pkexec():
-            self.updatedb_process = SudoDialog.env_spawn('pkexec updatedb', 1)
+            if sys.platform.startswith('linux'):
+                self.updatedb_process = SudoDialog.env_spawn('pkexec updatedb', 1)
+            elif 'bsd' in sys.platform or sys.platform.startswith('dragonfly'):
+                self.updatedb_process = SudoDialog.env_spawn('pkexec /usr/libexec/locate.updatedb', 1)
         else:
-            self.updatedb_process = SudoDialog.env_spawn('sudo updatedb', 1)
+            if sys.platform.startswith('linux'):
+                self.updatedb_process = SudoDialog.env_spawn('sudo updatedb', 1)
+            elif 'bsd' in sys.platform or sys.platform.startswith('dragonfly'):
+                self.updatedb_process = SudoDialog.env_spawn('sudo /usr/libexec/locate.updatedb', 1)
             try:
                 # Check for password prompt or program exit.
                 self.updatedb_process.expect(".*ssword.*")
