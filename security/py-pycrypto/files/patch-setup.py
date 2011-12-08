--- setup.py.orig	2011-11-01 17:47:23.000000000 +0400
+++ setup.py	2011-11-01 17:54:51.000000000 +0400
@@ -177,6 +177,7 @@
                 # especially helps the DES modules.
                 self.__add_compiler_option("-O3")
                 self.__add_compiler_option("-fomit-frame-pointer")
+                self.__add_compiler_option("-D_WCHAR_T_DEFINED")
                 # Don't include debug symbols unless debugging
                 self.__remove_compiler_option("-g")
                 # Don't include profiling information (incompatible with
