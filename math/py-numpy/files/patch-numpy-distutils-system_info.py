--- numpy/distutils/system_info.py.orig	2013-02-09 22:04:56.000000000 +0100
+++ numpy/distutils/system_info.py	2013-03-22 21:01:34.000000000 +0100
@@ -983,8 +983,8 @@
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
