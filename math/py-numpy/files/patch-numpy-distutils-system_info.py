--- numpy/distutils/system_info.py.orig	Tue Oct  3 00:35:22 2006
+++ numpy/distutils/system_info.py	Sun Feb  4 19:46:15 2007
@@ -860,6 +860,8 @@
         atlas_1 = None
         for d in lib_dirs:
             atlas = self.check_libs2(d,atlas_libs,[])
+            if atlas is not None:
+                atlas['libraries'].extend(['gfortran', 'm', 'pthread'])
             lapack_atlas = self.check_libs2(d,['lapack_atlas'],[])
             if atlas is not None:
                 lib_dirs2 = [d] + self.combine_paths(d,['atlas*','ATLAS*'])
@@ -935,6 +937,7 @@
             else:
                 info['language'] = 'f77'
 
+        info['language'] = 'f77'
         self.set_info(**info)
 
 class atlas_blas_info(atlas_info):
@@ -1188,8 +1191,9 @@
         atlas_version = None
         need_lapack = 0
         need_blas = 0
+	lapack_type = self.cp.get(self.section, 'lapack_type').strip()
         info = {}
-        if atlas_info:
+        if lapack_type == 'atlas' and atlas_info:
             version_info = atlas_info.copy()
             atlas_version = get_atlas_version(**version_info)
             if not atlas_info.has_key('define_macros'):
