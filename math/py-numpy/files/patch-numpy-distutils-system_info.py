--- numpy/distutils/system_info.py.orig	Tue Oct  3 00:35:22 2006
+++ numpy/distutils/system_info.py	Sat Dec  9 22:51:47 2006
@@ -860,6 +860,8 @@
         atlas_1 = None
         for d in lib_dirs:
             atlas = self.check_libs2(d,atlas_libs,[])
+            if atlas is not None:
+                atlas['libraries'].extend(['g2c', 'm', 'pthread'])
             lapack_atlas = self.check_libs2(d,['lapack_atlas'],[])
             if atlas is not None:
                 lib_dirs2 = [d] + self.combine_paths(d,['atlas*','ATLAS*'])
