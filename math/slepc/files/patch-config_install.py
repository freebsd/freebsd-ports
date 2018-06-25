--- config/install.py.orig	2018-06-25 08:07:05 UTC
+++ config/install.py
@@ -295,11 +295,11 @@ for dir in dirs:
 
   def installShare(self):
     self.copies.extend(self.copytree(self.rootShareDir, self.destShareDir))
-    if os.path.exists(os.path.join(self.destShareDir,'slepc','examples')):
-      shutil.rmtree(os.path.join(self.destShareDir,'slepc','examples'))
-    os.mkdir(os.path.join(self.destShareDir,'slepc','examples'))
-    self.copyExamples(self.rootDir,os.path.join(self.destShareDir,'slepc','examples'))
-    self.fixExamplesMakefile(os.path.join(self.destShareDir,'slepc','examples','makefile'))
+    if os.path.exists(os.path.join(self.destShareDir,'examples','slepc')):
+      shutil.rmtree(os.path.join(self.destShareDir,'examples','slepc'))
+    os.mkdir(os.path.join(self.destShareDir,'examples','slepc'))
+    self.copyExamples(self.rootDir,os.path.join(self.destShareDir,'examples','slepc'))
+    self.fixExamplesMakefile(os.path.join(self.destShareDir,'examples','slepc','makefile'))
     return
 
   def copyLib(self, src, dst):
