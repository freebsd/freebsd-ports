--- ./setup.py.orig	Tue Feb  1 02:50:11 2005
+++ ./setup.py	Sat Sep 30 17:49:08 2006
@@ -9,7 +9,7 @@
 from distutils.core import setup, Extension
 from distutils.command.build import build    # nidsMaker
 from distutils.spawn import spawn            # nidsMaker.run()
-import os, os.path
+import os, os.path, shutil
 
 pathjoin = os.path.join
 
@@ -32,12 +32,15 @@
     def buildNids(self):
         # extremely crude package builder
         try:
-            os.stat(self.NIDSDIR)
+            os.stat(self.NIDSDIR + '/.done')
             return None           # assume already built
         except OSError:
             pass
 
-        spawn(['tar', '-xf', self.NIDSTAR], search_path = 1)
+        spawn(['touch', self.NIDSDIR + '/.done'], search_path = 1)
+
+	shutil.copyfile("config.guess",pathjoin(self.NIDSDIR,"config.guess"))
+	shutil.copyfile("config.sub",pathjoin(self.NIDSDIR,"config.sub"))
         os.chdir(self.NIDSDIR)
         for p in self.patches:
             spawn(['patch', '-c', '-p1', '-i', pathjoin('..', p)], search_path = 1)
