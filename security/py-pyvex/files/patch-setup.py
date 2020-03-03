--- setup.py.orig	2020-01-08 00:58:26 UTC
+++ setup.py
@@ -73,10 +73,8 @@ def _build_vex():
     e['MULTIARCH'] = '1'
     e['DEBUG'] = '1'
 
-    cmd1 = ['nmake', '/f', 'Makefile-msvc', 'all']
-    cmd2 = ['make', '-f', 'Makefile-gcc', '-j', str(multiprocessing.cpu_count()), 'all']
-    cmd3 = ['gmake', '-f', 'Makefile-gcc', '-j', str(multiprocessing.cpu_count()), 'all']
-    for cmd in (cmd1, cmd2, cmd3):
+    cmd3 = ['gmake', '-f', 'Makefile-gcc', '-j', '%%MAKE_JOBS_NUMBER%%', 'all']
+    for cmd in (cmd3,):
         try:
             if subprocess.call(cmd, cwd=VEX_PATH, env=e) == 0:
                 break
@@ -91,10 +89,8 @@ def _build_pyvex():
     e['VEX_INCLUDE_PATH'] = os.path.join(VEX_PATH, 'pub')
     e['VEX_LIB_FILE'] = os.path.join(VEX_PATH, 'libvex.lib')
 
-    cmd1 = ['nmake', '/f', 'Makefile-msvc']
-    cmd2 = ['make', '-j', str(multiprocessing.cpu_count())]
-    cmd3 = ['gmake', '-j', str(multiprocessing.cpu_count())]
-    for cmd in (cmd1, cmd2, cmd3):
+    cmd3 = ['gmake', '-j', '%%MAKE_JOBS_NUMBER%%']
+    for cmd in (cmd3,):
         try:
             if subprocess.call(cmd, cwd='pyvex_c', env=e) == 0:
                 break
