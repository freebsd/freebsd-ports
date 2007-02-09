--- numpy/distutils/fcompiler/gnu.py.orig	Mon Oct  9 03:46:59 2006
+++ numpy/distutils/fcompiler/gnu.py	Thu Jan 25 21:48:15 2007
@@ -22,7 +22,7 @@
     #         GNU Fortran 0.5.25 20010319 (prerelease)
     # Redhat: GNU Fortran (GCC 3.2.2 20030222 (Red Hat Linux 3.2.2-5)) 3.2.2 20030222 (Red Hat Linux 3.2.2-5)
 
-    for fc_exe in map(find_executable,['g77','f77']):
+    for fc_exe in map(find_executable,['gfortran', 'gfortran41', 'gfortran42', 'g77','f77']):
         if os.path.isfile(fc_exe):
             break
     executables = {
@@ -247,7 +247,7 @@
     # OS X: GNU Fortran 95 (GCC) 4.1.0
     #       GNU Fortran 95 (GCC) 4.2.0 20060218 (experimental)
 
-    for fc_exe in map(find_executable,['gfortran','f95']):
+    for fc_exe in map(find_executable,['gfortran','gfortran41','gfortran42','gfortran43','f95']):
         if os.path.isfile(fc_exe):
             break
     executables = {
