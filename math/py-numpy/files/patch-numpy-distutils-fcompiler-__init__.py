--- numpy/distutils/fcompiler/__init__.py.orig	Wed Oct 11 22:28:42 2006
+++ numpy/distutils/fcompiler/__init__.py	Sat Dec  9 22:51:47 2006
@@ -273,11 +273,7 @@
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
