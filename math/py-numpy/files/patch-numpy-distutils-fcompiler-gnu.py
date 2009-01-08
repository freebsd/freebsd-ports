--- numpy/distutils/fcompiler/gnu.py.orig	2007-11-07 16:05:14.000000000 -0600
+++ numpy/distutils/fcompiler/gnu.py	2008-04-07 13:54:56.000000000 -0500
@@ -48,7 +48,7 @@
     # Redhat: GNU Fortran (GCC 3.2.2 20030222 (Red Hat Linux 3.2.2-5)) 3.2.2 20030222 (Red Hat Linux 3.2.2-5)
     # GNU Fortran (GCC) 3.4.2 (mingw-special)
 
-    possible_executables = ['g77', 'f77']
+    possible_executables = ['%%FC%%', 'g77', 'f77']
     executables = {
         'version_cmd'  : [None, "--version"],
         'compiler_f77' : [None, "-g", "-Wall", "-fno-second-underscore"],
@@ -72,7 +72,7 @@
         for key in ['version_cmd', 'compiler_f77', 'linker_so', 'linker_exe']:
             executables[key].append('-mno-cygwin')
 
-    g2c = 'g2c'
+    g2c = '%%FC%%'
 
     suggested_f90_compiler = 'gnu95'
 
@@ -295,7 +295,7 @@
     #       GNU Fortran 95 (GCC) 4.2.0 20060218 (experimental)
     #       GNU Fortran (GCC) 4.3.0 20070316 (experimental)
 
-    possible_executables = ['gfortran', 'f95']
+    possible_executables = ['%%FC%%', 'gfortran', 'f95']
     executables = {
         'version_cmd'  : ["<F90>", "--version"],
         'compiler_f77' : [None, "-Wall", "-ffixed-form",
