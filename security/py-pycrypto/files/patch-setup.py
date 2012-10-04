--- ./setup.py.orig	2012-10-03 15:57:50.000000000 +1000
+++ ./setup.py	2012-10-03 15:57:50.000000000 +1000
@@ -136,6 +136,7 @@
                 # especially helps the DES modules.
                 self.__add_compiler_option("-O3")
                 self.__add_compiler_option("-fomit-frame-pointer")
+                self.__add_compiler_option("-D_WCHAR_T_DEFINED")
                 # Don't include debug symbols unless debugging
                 self.__remove_compiler_option("-g")
                 # Don't include profiling information (incompatible with
