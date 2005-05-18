
$FreeBSD$

--- scipy_core/scipy_distutils/system_info.py.orig
+++ scipy_core/scipy_distutils/system_info.py
@@ -548,8 +548,8 @@
         lib_dirs = self.get_lib_dirs()
         info = {}
         atlas_libs = self.get_libs('atlas_libs',
-                                   self._lib_names + ['atlas'])
-        lapack_libs = self.get_libs('lapack_libs',['lapack'])
+                                   self._lib_names + ['atlas_r'])
+        lapack_libs = self.get_libs('lapack_libs',['alapack_r'])
         atlas = None
         lapack = None
         atlas_1 = None
