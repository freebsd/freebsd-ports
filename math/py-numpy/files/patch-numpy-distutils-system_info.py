--- numpy/distutils/system_info.py.orig	2007-11-07 16:05:15.000000000 -0600
+++ numpy/distutils/system_info.py	2008-04-07 11:39:05.000000000 -0500
@@ -883,6 +883,7 @@
             atlas = self.check_libs2(d,atlas_libs,[])
             lapack_atlas = self.check_libs2(d,['lapack_atlas'],[])
             if atlas is not None:
+                atlas['libraries'].extend(['gfortran', 'm', 'pthread'])
                 lib_dirs2 = [d] + self.combine_paths(d,['atlas*','ATLAS*'])
                 for d2 in lib_dirs2:
                     lapack = self.check_libs2(d2,lapack_libs,[])
@@ -1324,8 +1325,9 @@
             atlas_info = get_info('atlas_blas')
         atlas_version = None
         need_blas = 0
+        lapack_type = self.cp.get(self.section, 'lapack_type').strip()
         info = {}
-        if atlas_info:
+        if lapack_type == 'atlas' and atlas_info:
             version_info = atlas_info.copy()
             atlas_version = get_atlas_version(**version_info)
             if not atlas_info.has_key('define_macros'):
