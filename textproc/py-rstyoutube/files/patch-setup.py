--- setup.py.orig	2011-12-15 22:08:27.000000000 +0100
+++ setup.py	2011-12-16 21:07:37.000000000 +0100
@@ -1,6 +1,21 @@
 #!/usr/bin/env python
 
 from setuptools import setup
+import glob
+import os
+
+def rename_script(files):
+    import shutil
+
+    if files:
+        dirname = os.path.abspath(os.path.join('bin', '_script'))
+        if not os.path.exists(dirname):
+            os.makedirs(dirname)
+            for file in files:
+                shutil.copyfile(file, os.path.join(dirname, os.path.basename(file[:-3]).replace('+', '_')))
+
+# Rename script file (without .py)
+rename_script(glob.glob('bin/*.py'))
 
 setup(
     name='rstyoutube',
@@ -11,7 +26,7 @@
     author_email='jcd@sdf.lonestar.org',
     url='http://bitbucket.org/cliff/rstyoutube',
     py_modules=['rstyoutube'],
-    scripts=['bin/rst2html+youtube.py'],
+    scripts= glob.glob('bin/_script/*'),
     license='LICENSE.txt',
     install_requires=[
         'docutils',
