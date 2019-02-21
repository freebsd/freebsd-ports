--- numpy/distutils/system_info.py.orig	2019-01-31 02:31:08 UTC
+++ numpy/distutils/system_info.py
@@ -169,6 +169,8 @@ def _c_string_literal(s):
     Convert a python string into a literal suitable for inclusion into C code
     """
     # only these three characters are forbidden in C strings
+    if s is None:
+        return '"None"'
     s = s.replace('\\', r'\\')
     s = s.replace('"',  r'\"')
     s = s.replace('\n', r'\n')
@@ -1109,8 +1111,8 @@ class atlas_info(system_info):
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
@@ -1630,11 +1632,6 @@ class blas_opt_info(system_info):
             self.set_info(**blis_info)
             return
 
-        openblas_info = get_info('openblas')
-        if openblas_info:
-            self.set_info(**openblas_info)
-            return
-
         atlas_info = get_info('atlas_3_10_blas_threads')
         if not atlas_info:
             atlas_info = get_info('atlas_3_10_blas')
