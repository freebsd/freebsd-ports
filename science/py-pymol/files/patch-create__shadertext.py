--- create_shadertext.py.orig	2017-03-09 18:16:07 UTC
+++ create_shadertext.py
@@ -93,19 +93,20 @@ def create_shadertext(shaderdir, shaderd
 
 def create_buildinfo(outputdir, pymoldir='.'):
 
-    try:
-        sha = Popen(['git', 'rev-parse', 'HEAD'], cwd=pymoldir,
-                stdout=PIPE).stdout.read().strip().decode()
-    except OSError:
-        sha = ''
+    #try:
+    #    sha = Popen(['git', 'rev-parse', 'HEAD'], cwd=pymoldir,
+    #            stdout=PIPE).stdout.read().strip().decode()
+    #except OSError:
+    #    sha = ''
+    sha = 'n/a'
 
     rev = 0
-    try:
-        for line in Popen(['svn', 'info'], cwd=pymoldir, stdout=PIPE).stdout:
-            if line.startswith(b'Last Changed Rev'):
-                rev = int(line.split()[3])
-    except OSError:
-        pass
+    #try:
+    #    for line in Popen(['svn', 'info'], cwd=pymoldir, stdout=PIPE).stdout:
+    #        if line.startswith(b'Last Changed Rev'):
+    #            rev = int(line.split()[3])
+    #except OSError:
+    #    pass
 
     with openw(os.path.join(outputdir, 'PyMOLBuildInfo.h')) as out:
         print('''
