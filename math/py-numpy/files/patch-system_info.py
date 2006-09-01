--- numpy/distutils/system_info.py.orig	Thu Jul 27 19:44:41 2006
+++ numpy/distutils/system_info.py	Thu Jul 27 19:39:18 2006
@@ -811,7 +811,7 @@
     dir_env_var = 'ATLAS'
     _lib_names = ['f77blas','cblas']
     if sys.platform[:7]=='freebsd':
-        _lib_atlas = ['atlas_r']
+        _lib_atlas = ['atlas_r', 'g2c']
         _lib_lapack = ['alapack_r']
     else:
         _lib_atlas = ['atlas']
