--- uliweb/utils/setup.py.orig	2013-12-26 16:36:45.000000000 +0800
+++ uliweb/utils/setup.py	2013-12-26 16:36:56.000000000 +0800
@@ -4,10 +4,6 @@
 
 #remove build and dist directory
 import shutil
-if os.path.exists('build'):
-    shutil.rmtree('build')
-if os.path.exists('dist'):
-    shutil.rmtree('dist')
 
 def copy_dir(self, package, src, dst):
     self.mkpath(dst)
