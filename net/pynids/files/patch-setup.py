--- ./setup.py.orig	2010-05-09 14:01:38.000000000 -0400
+++ ./setup.py	2010-12-21 17:34:04.929916874 -0500
@@ -8,7 +8,7 @@
 from distutils.core import setup, Extension
 from distutils.command.build import build    # nidsMaker
 from distutils.spawn import spawn            # nidsMaker.run()
-import os, os.path
+import os, os.path, shutil
 
 pathjoin = os.path.join
 
@@ -30,12 +30,14 @@
     def buildNids(self):
         # extremely crude package builder
         try:
-            os.stat(self.NIDSDIR)
+            os.stat(self.NIDSDIR + '/.done')
             return None           # assume already built
         except OSError:
             pass
 
-        spawn(['tar', '-zxf', self.NIDSTAR], search_path = 1)
+        spawn(['touch', self.NIDSDIR + '/.done'], search_path = 1)
+        shutil.copyfile("config.guess",pathjoin(self.NIDSDIR,"config.guess"))
+        shutil.copyfile("config.sub",pathjoin(self.NIDSDIR,"config.sub"))
         os.chdir(self.NIDSDIR)
         spawn([pathjoin('.','configure'), 'CFLAGS=-fPIC'])
         spawn(['make'], search_path = 1)
