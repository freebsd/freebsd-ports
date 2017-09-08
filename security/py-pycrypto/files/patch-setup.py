--- setup.py.orig	2017-09-07 17:16:26 UTC
+++ setup.py
@@ -136,6 +136,7 @@ class PCTBuildExt (build_ext):
                 # especially helps the DES modules.
                 self.__add_compiler_option("-O3")
                 self.__add_compiler_option("-fomit-frame-pointer")
+                self.__add_compiler_option("-D_WCHAR_T_DEFINED")
                 # Don't include debug symbols unless debugging
                 self.__remove_compiler_option("-g")
                 # Don't include profiling information (incompatible with
