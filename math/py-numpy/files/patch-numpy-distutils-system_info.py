--- numpy/distutils/system_info.py.orig	2010-11-18 05:11:51.000000000 -0600
+++ numpy/distutils/system_info.py	2011-10-08 11:34:44.399179056 -0500
@@ -909,8 +909,8 @@
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
@@ -938,6 +938,7 @@
             atlas = self.check_libs2(d,atlas_libs,[])
             lapack_atlas = self.check_libs2(d,['lapack_atlas'],[])
             if atlas is not None:
+                atlas['libraries'].extend(['gfortran', 'm', 'pthread'])
                 lib_dirs2 = [d] + self.combine_paths(d,['atlas*','ATLAS*'])
                 for d2 in lib_dirs2:
                     lapack = self.check_libs2(d2,lapack_libs,[])
@@ -1383,8 +1384,9 @@
             atlas_info = get_info('atlas_blas')
         atlas_version = None
         need_blas = 0
+        lapack_type = self.cp.get(self.section, 'lapack_type').strip()
         info = {}
-        if atlas_info:
+        if lapack_type == 'atlas' and atlas_info:
             version_info = atlas_info.copy()
             atlas_version = get_atlas_version(**version_info)
             if 'define_macros' not in atlas_info: