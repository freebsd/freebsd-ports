--- numpy/distutils/fcompiler/gnu.py.orig	Mon Mar 26 14:27:13 2007
+++ numpy/distutils/fcompiler/gnu.py	Mon Jun 11 11:55:16 2007
@@ -21,7 +21,7 @@
     #         GNU Fortran 0.5.25 20010319 (prerelease)
     # Redhat: GNU Fortran (GCC 3.2.2 20030222 (Red Hat Linux 3.2.2-5)) 3.2.2 20030222 (Red Hat Linux 3.2.2-5)
 
-    for fc_exe in map(find_executable,['g77','f77']):
+    for fc_exe in map(find_executable,['gfortran', 'gfortran42', 'g77','f77']):
         if os.path.isfile(fc_exe):
             break
     executables = {
@@ -47,7 +47,7 @@
         for key in ['version_cmd', 'compiler_f77', 'linker_so', 'linker_exe']:
             executables[key].append('-mno-cygwin')
 
-    g2c = 'g2c'
+    g2c = 'gfortran'
 
     suggested_f90_compiler = 'gnu95'
 
@@ -258,7 +258,7 @@
     #       GNU Fortran 95 (GCC) 4.2.0 20060218 (experimental)
     #       GNU Fortran (GCC) 4.3.0 20070316 (experimental)
 
-    for fc_exe in map(find_executable,['gfortran','f95']):
+    for fc_exe in map(find_executable,['gfortran','gfortran42','f95']):
         if os.path.isfile(fc_exe):
             break
     executables = {
