--- setup.py.orig	2013-10-14 21:38:10 UTC
+++ setup.py
@@ -136,6 +136,7 @@ class PCTBuildExt (build_ext):
                 # especially helps the DES modules.
                 self.__add_compiler_option("-O3")
                 self.__add_compiler_option("-fomit-frame-pointer")
+                self.__add_compiler_option("-D_WCHAR_T_DEFINED")
                 # Don't include debug symbols unless debugging
                 self.__remove_compiler_option("-g")
                 # Don't include profiling information (incompatible with
