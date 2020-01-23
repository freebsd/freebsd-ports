--- numpy/distutils/system_info.py.orig	2019-08-27 19:01:36 UTC
+++ numpy/distutils/system_info.py
@@ -172,6 +172,8 @@ def _c_string_literal(s):
     Convert a python string into a literal suitable for inclusion into C code
     """
     # only these three characters are forbidden in C strings
+    if s is None:
+        return '"None"'
     s = s.replace('\\', r'\\')
     s = s.replace('"',  r'\"')
     s = s.replace('\n', r'\n')
@@ -1112,8 +1114,8 @@ class atlas_info(system_info):
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
@@ -1633,11 +1635,6 @@ class blas_opt_info(system_info):
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
@@ -1742,7 +1739,7 @@ class blas_info(system_info):
                                       library_dirs=info['library_dirs'],
                                       extra_postargs=info.get('extra_link_args', []))
                     res = "blas"
-            except distutils.ccompiler.CompileError:
+            except (distutils.ccompiler.CompileError, distutils.ccompiler.LinkError):
                 res = None
         finally:
             shutil.rmtree(tmpdir)
