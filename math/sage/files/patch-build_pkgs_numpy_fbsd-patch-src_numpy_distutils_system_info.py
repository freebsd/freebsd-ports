--- /dev/null	2014-01-29 03:00:00.000000000 +0000
+++ build/pkgs/numpy/fbsd-patch-src_numpy_distutils_system_info.py	2014-01-29 03:01:19.000000000 +0000
@@ -0,0 +1,13 @@
+--- src/numpy/distutils/system_info.py.orig	2013-02-09 21:04:56.000000000 +0000
++++ src/numpy/distutils/system_info.py	2013-05-27 21:51:12.000000000 +0000
+@@ -983,8 +983,8 @@
+     dir_env_var = 'ATLAS'
+     _lib_names = ['f77blas', 'cblas']
+     if sys.platform[:7] == 'freebsd':
+-        _lib_atlas = ['atlas_r']
+-        _lib_lapack = ['alapack_r']
++        _lib_atlas = ['atlas']
++        _lib_lapack = ['alapack']
+     else:
+         _lib_atlas = ['atlas']
+         _lib_lapack = ['lapack']
