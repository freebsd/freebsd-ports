--- numpy/distutils/system_info.py.orig	2021-05-09 10:38:00 UTC
+++ numpy/distutils/system_info.py
@@ -209,6 +209,8 @@ def _c_string_literal(s):
     Convert a python string into a literal suitable for inclusion into C code
     """
     # only these three characters are forbidden in C strings
+    if s is None:
+        return '"None"'
     s = s.replace('\\', r'\\')
     s = s.replace('"',  r'\"')
     s = s.replace('\n', r'\n')
@@ -1322,8 +1324,8 @@ class atlas_info(system_info):
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
