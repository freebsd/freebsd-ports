--- ./setup.py.orig	2009-12-13 21:39:29.000000000 +0100
+++ ./setup.py	2009-12-14 16:48:47.000000000 +0100
@@ -136,6 +136,7 @@
                 # especially helps the DES modules.
                 self.__add_compiler_option("-O3")
                 self.__add_compiler_option("-fomit-frame-pointer")
+                self.__add_compiler_option("-D_WCHAR_T_DEFINED")
                 # Don't include debug symbols unless debugging
                 self.__remove_compiler_option("-g")
             if USE_GCOV:
@@ -152,7 +153,7 @@
             self.compiler.include_dirs.insert(0, "src/inc-msvc/")
 
         # Detect libgmp and don't build _fastmath if it is missing.
-        lib_dirs = self.compiler.library_dirs + ['/lib', '/usr/lib']
+        lib_dirs = self.compiler.library_dirs + ['/lib', '/usr/lib', '%%LOCALBASE%%/lib']
         if not (self.compiler.find_library_file(lib_dirs, 'gmp')):
             print >>sys.stderr, "warning: GMP library not found; Not building Crypto.PublicKey._fastmath."
             self.__remove_extensions(["Crypto.PublicKey._fastmath"])
@@ -259,6 +260,7 @@
             Extension("Crypto.PublicKey._fastmath",
                       include_dirs=['src/'],
                       libraries=['gmp'],
+                      library_dirs=['%%LOCALBASE%%/lib'],
                       sources=["src/_fastmath.c"]),
 
             # Hash functions
