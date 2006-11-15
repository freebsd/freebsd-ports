--- numpy/distutils/system_info.py.orig	Sun Jul 30 11:08:48 2006
+++ numpy/distutils/system_info.py	Fri Sep 29 12:22:29 2006
@@ -855,6 +855,8 @@
         atlas_1 = None
         for d in lib_dirs:
             atlas = self.check_libs2(d,atlas_libs,[])
+            if atlas is not None:
+                atlas['libraries'].extend(['g2c', 'm', 'pthread'])
             lapack_atlas = self.check_libs2(d,['lapack_atlas'],[])
             if atlas is not None:
                 lib_dirs2 = [d] + self.combine_paths(d,['atlas*','ATLAS*'])
