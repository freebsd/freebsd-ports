--- numpy/distutils/fcompiler/gnu.py~	Mon Oct  9 16:46:59 2006
+++ numpy/distutils/fcompiler/gnu.py	Wed Jan 17 12:26:12 2007
@@ -247,7 +247,7 @@
     # OS X: GNU Fortran 95 (GCC) 4.1.0
     #       GNU Fortran 95 (GCC) 4.2.0 20060218 (experimental)
 
-    for fc_exe in map(find_executable,['gfortran','f95']):
+    for fc_exe in map(find_executable,['gfortran','gfortran41','gfortran42','gfortran43','f95']):
         if os.path.isfile(fc_exe):
             break
     executables = {
