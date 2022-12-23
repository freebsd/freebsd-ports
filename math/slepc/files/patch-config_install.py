--- config/install.py.orig	2022-12-21 10:04:56 UTC
+++ config/install.py
@@ -331,7 +331,7 @@ for dir in dirs:
 
   def installShare(self):
     self.copies.extend(self.copytree(self.rootShareDir, self.destShareDir))
-    examplesdir=os.path.join(self.destShareDir,'slepc','examples')
+    examplesdir=os.path.join(self.destShareDir,'examples','slepc')
     if os.path.exists(examplesdir):
       shutil.rmtree(examplesdir)
     os.mkdir(examplesdir)
