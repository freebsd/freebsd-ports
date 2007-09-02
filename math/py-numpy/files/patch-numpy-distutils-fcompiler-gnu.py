--- numpy/distutils/fcompiler/gnu.py.orig	2007-08-20 21:00:55.000000000 -0500
+++ numpy/distutils/fcompiler/gnu.py	2007-08-27 15:12:10.000000000 -0500
@@ -67,12 +67,12 @@
         for key in ['version_cmd', 'compiler_f77', 'linker_so', 'linker_exe']:
             executables[key].append('-mno-cygwin')
 
-    g2c = 'g2c'
+    g2c = 'gfortran'
 
     suggested_f90_compiler = 'gnu95'
 
     def find_executables(self):
-        for fc_exe in [find_executable(c) for c in ['g77','f77']]:
+        for fc_exe in [find_executable(c) for c in ['gfortran', 'gfortran42', 'g77','f77']]:
             if os.path.isfile(fc_exe):
                 break
         for key in ['version_cmd', 'compiler_f77', 'linker_so', 'linker_exe']:
@@ -318,7 +318,7 @@
     g2c = 'gfortran'
 
     def find_executables(self):
-        for fc_exe in [find_executable(c) for c in ['gfortran','f95']]:
+        for fc_exe in [find_executable(c) for c in ['gfortran', 'gfortran42', 'f95']]:
             if os.path.isfile(fc_exe):
                 break
         for key in ['version_cmd', 'compiler_f77', 'compiler_f90',
