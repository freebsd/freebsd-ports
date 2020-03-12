--- setup.py.orig	2020-03-02 20:55:10 UTC
+++ setup.py
@@ -68,7 +68,7 @@ def _build_native():
             pass
 
     cmd1 = ['nmake', '/f', 'Makefile-win']
-    cmd2 = ['make']
+    cmd2 = ['gmake']
     for cmd in (cmd1, cmd2):
         try:
             if subprocess.call(cmd, cwd='native', env=env) != 0:
