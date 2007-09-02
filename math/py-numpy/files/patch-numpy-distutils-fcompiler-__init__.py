--- numpy/distutils/fcompiler/__init__.py.orig	2007-08-20 21:00:55.000000000 -0500
+++ numpy/distutils/fcompiler/__init__.py	2007-08-27 19:26:14.000000000 -0500
@@ -78,7 +78,7 @@
         'ranlib'       : None,
         }
 
-    compile_switch = "-c"
+    compile_switch = "-c -fPIC"
     object_switch = "-o "   # Ending space matters! It will be stripped
                             # but if it is missing then object_switch
                             # will be prefixed to object file name by
@@ -278,11 +278,7 @@
         f90 = self.__get_cmd('compiler_f90','F90',(conf,'f90exec'))
         # Temporarily setting f77,f90 compilers so that
         # version_cmd can use their executables.
-        if f77:
-            self.set_executables(compiler_f77=[f77])
-        if f90:
-            self.set_executables(compiler_f90=[f90])
-
+	# If you do that, --f77exec and --f90exec break -db
         # Must set version_cmd before others as self.get_flags*
         # methods may call self.get_version.
         vers_cmd = self.__get_cmd(self.get_version_cmd)
