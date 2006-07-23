--- python/PETSc/packages/BlasLapack.py.orig	Fri Jul 21 04:44:48 2006
+++ python/PETSc/packages/BlasLapack.py	Sat Jul 22 13:57:25 2006
@@ -117,14 +117,13 @@
     foundBlas = self.checkBlas(blasLibrary, self.getOtherLibs(foundBlas, blasLibrary), mangleFunc)
     if foundBlas:
       foundLapack = self.checkLapack(lapackLibrary, self.getOtherLibs(foundBlas, blasLibrary), mangleFunc)
-    elif not hasattr(self.compilers, 'FC'):
-      self.framework.logPrint('Checking cblaslapack')
-      foundcBlasLapack = self.checkBlas(blasLibrary, self.getOtherLibs(foundBlas, blasLibrary), 0, 'f2cblaslapack_id_')
-      if foundcBlasLapack:
-        foundBlas = self.checkBlas(blasLibrary, self.getOtherLibs(foundBlas, blasLibrary), 0, 'ddot_')
+    else:
+      self.framework.logPrint('Checking cblaslapack name-mangling')
+      foundBlas = self.checkBlas(blasLibrary, self.getOtherLibs(foundBlas, blasLibrary), 0, 'ddot_')
+      if foundBlas:
+        self.framework.logPrint('Found cblaslapack')
         foundLapack = self.checkLapack(lapackLibrary, self.getOtherLibs(foundBlas, blasLibrary), 0, ['dgetrs_', 'dgeev_'])
-        if foundBlas and foundLapack:
-          self.framework.logPrint('Found cblaslapack')
+        if foundLapack:
           self.f2c = 1
     return (foundBlas, foundLapack)
 
