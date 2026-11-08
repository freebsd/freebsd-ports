--- config/BuildSystem/config/packages/HPDDM.py.orig	2026-09-29 03:42:55 UTC
+++ config/BuildSystem/config/packages/HPDDM.py
@@ -12,10 +12,11 @@ class Configure(config.package.Package):
     self.buildLanguages         = ['Cxx']
     self.functions              = []
     self.includes               = ['HPDDM.hpp']
-    self.skippackagewithoptions = 1
+    self.skippackagewithoptions = 0
     self.linkedbypetsc          = 0
-    self.builtafterpetsc        = 1
+    self.builtafterpetsc        = 0
     self.hastestsdatafiles      = 1
+    self.liblist                = []
     return
 
   def setupDependencies(self,framework):
