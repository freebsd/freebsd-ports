--- numpy/distutils/system_info.py.orig	2016-10-03 23:42:24 UTC
+++ numpy/distutils/system_info.py
@@ -1038,8 +1038,8 @@ class atlas_info(system_info):
     dir_env_var = 'ATLAS'
     _lib_names = ['f77blas', 'cblas']
     if sys.platform[:7] == 'freebsd':
-        _lib_atlas = ['atlas_r']
-        _lib_lapack = ['alapack_r']
+        _lib_atlas = ['atlas']
+        _lib_lapack = ['alapack']
     else:
         _lib_atlas = ['atlas']
         _lib_lapack = ['lapack']
@@ -1574,11 +1574,6 @@ class blas_opt_info(system_info):
             self.set_info(**blas_mkl_info)
             return
 
-        openblas_info = get_info('openblas')
-        if openblas_info:
-            self.set_info(**openblas_info)
-            return
-
         atlas_info = get_info('atlas_3_10_blas_threads')
         if not atlas_info:
             atlas_info = get_info('atlas_3_10_blas')
