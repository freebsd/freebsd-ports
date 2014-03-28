--- numpy/distutils/fcompiler/gnu.py.orig	2013-10-30 22:31:40.000000000 +0400
+++ numpy/distutils/fcompiler/gnu.py	2014-02-24 15:11:58.000000000 +0400
@@ -66,7 +66,7 @@
     # Redhat: GNU Fortran (GCC 3.2.2 20030222 (Red Hat Linux 3.2.2-5)) 3.2.2 20030222 (Red Hat Linux 3.2.2-5)
     # GNU Fortran (GCC) 3.4.2 (mingw-special)
 
-    possible_executables = ['g77', 'f77']
+    possible_executables = ['%%FC%%', 'g77', 'f77']
     executables = {
         'version_cmd'  : [None, "--version"],
         'compiler_f77' : [None, "-g", "-Wall", "-fno-second-underscore"],
@@ -90,7 +90,7 @@
         for key in ['version_cmd', 'compiler_f77', 'linker_so', 'linker_exe']:
             executables[key].append('-mno-cygwin')
 
-    g2c = 'g2c'
+    g2c = '%%FC%%'
 
     suggested_f90_compiler = 'gnu95'
 
@@ -103,6 +103,8 @@
 
     def get_flags_linker_so(self):
         opt = self.linker_so[1:]
+        if 'FFLAGS' in os.environ:
+                opt.append(os.environ['FFLAGS'])
         if sys.platform=='darwin':
             target = os.environ.get('MACOSX_DEPLOYMENT_TARGET', None)
             # If MACOSX_DEPLOYMENT_TARGET is set, we simply trust the value
@@ -249,7 +251,7 @@
     #       GNU Fortran 95 (GCC) 4.2.0 20060218 (experimental)
     #       GNU Fortran (GCC) 4.3.0 20070316 (experimental)
 
-    possible_executables = ['gfortran', 'f95']
+    possible_executables = ['%%FC%%', 'gfortran', 'f95']
     executables = {
         'version_cmd'  : ["<F90>", "--version"],
         'compiler_f77' : [None, "-Wall", "-ffixed-form",
