--- numpy/distutils/system_info.py.orig	2011-07-01 22:31:13.000000000 +0100
+++ numpy/distutils/system_info.py	2011-11-26 09:54:54.000000000 +0000
@@ -910,8 +910,8 @@
     dir_env_var = 'ATLAS'
     _lib_names = ['f77blas','cblas']
     if sys.platform[:7]=='freebsd':
-        _lib_atlas = ['atlas_r']
-        _lib_lapack = ['alapack_r']
+        _lib_atlas = ['atlas']
+        _lib_lapack = ['alapack']
     else:
         _lib_atlas = ['atlas']
         _lib_lapack = ['lapack']
@@ -939,6 +939,7 @@
             atlas = self.check_libs2(d,atlas_libs,[])
             lapack_atlas = self.check_libs2(d,['lapack_atlas'],[])
             if atlas is not None:
+                atlas['libraries'].extend(['gfortran', 'm', 'pthread'])
                 lib_dirs2 = [d] + self.combine_paths(d,['atlas*','ATLAS*'])
                 for d2 in lib_dirs2:
                     lapack = self.check_libs2(d2,lapack_libs,[])
