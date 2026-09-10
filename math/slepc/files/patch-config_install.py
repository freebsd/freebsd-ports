--- config/install.py.orig	2026-09-09 11:20:46 UTC
+++ config/install.py
@@ -492,7 +492,7 @@ for dir in dirs:
     else: exclude = ['datafiles']
     self.copies.extend(self.copytree(self.rootShareDir, self.destShareDir, exclude=exclude))
     if self.copyexamples:
-      examplesdir=os.path.join(self.destShareDir,'slepc','examples')
+      examplesdir=os.path.join(self.destShareDir,'examples','slepc')
       if os.path.exists(examplesdir):
         shutil.rmtree(examplesdir)
       os.mkdir(examplesdir)
