--- config/install.py.orig	2023-04-02 15:05:03 UTC
+++ config/install.py
@@ -336,7 +336,7 @@ for dir in dirs:
   def installShare(self):
     self.copies.extend(self.copytree(self.rootShareDir, self.destShareDir))
     if self.copyexamples:
-      examplesdir=os.path.join(self.destShareDir,'slepc','examples')
+      examplesdir=os.path.join(self.destShareDir,'examples','slepc')
       if os.path.exists(examplesdir):
         shutil.rmtree(examplesdir)
       os.mkdir(examplesdir)
