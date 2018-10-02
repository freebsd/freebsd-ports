--- config/install.py.orig	2018-10-02 22:50:33 UTC
+++ config/install.py
@@ -311,13 +311,13 @@ for dir in dirs:
 
   def installShare(self):
     self.copies.extend(self.copytree(self.rootShareDir, self.destShareDir))
-    examplesdir=os.path.join(self.destShareDir,'slepc','examples')
-    if os.path.exists(os.path.join(self.destShareDir,'slepc','examples')):
-      shutil.rmtree(os.path.join(self.destShareDir,'slepc','examples'))
-    os.mkdir(os.path.join(self.destShareDir,'slepc','examples'))
-    self.copyExamples(self.rootDir,os.path.join(self.destShareDir,'slepc','examples'))
+    examplesdir=os.path.join(self.destShareDir,'examples','slepc')
+    if os.path.exists(os.path.join(self.destShareDir,'examples','slepc')):
+      shutil.rmtree(os.path.join(self.destShareDir,'examples','slepc'))
+    os.mkdir(os.path.join(self.destShareDir,'examples','slepc'))
+    self.copyExamples(self.rootDir,os.path.join(self.destShareDir,'examples','slepc'))
     self.copyConfig(self.rootDir,examplesdir)
-    self.fixExamplesMakefile(os.path.join(self.destShareDir,'slepc','examples','makefile'))
+    self.fixExamplesMakefile(os.path.join(self.destShareDir,'examples','slepc','makefile'))
     return
 
   def copyLib(self, src, dst):
