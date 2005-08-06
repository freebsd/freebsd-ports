--- setup.py.orig	Tue Feb  1 06:50:11 2005
+++ setup.py	Sun Aug  7 00:08:43 2005
@@ -9,7 +9,7 @@
 from distutils.core import setup, Extension
 from distutils.command.build import build    # nidsMaker
 from distutils.spawn import spawn            # nidsMaker.run()
-import os, os.path
+import os, os.path, shutil
 
 pathjoin = os.path.join
 
@@ -38,6 +38,8 @@
             pass
 
         spawn(['tar', '-xf', self.NIDSTAR], search_path = 1)
+	shutil.copyfile("config.guess",pathjoin(self.NIDSDIR,"config.guess"))
+	shutil.copyfile("config.sub",pathjoin(self.NIDSDIR,"config.sub"))
         os.chdir(self.NIDSDIR)
         for p in self.patches:
             spawn(['patch', '-c', '-p1', '-i', pathjoin('..', p)], search_path = 1)
