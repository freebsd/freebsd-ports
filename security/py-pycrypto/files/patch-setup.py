--- setup.py.orig	2010-08-08 14:02:23.895825034 +0200
+++ setup.py	2010-08-08 14:04:31.663792751 +0200
@@ -139,6 +139,7 @@
                 # especially helps the DES modules.
                 self.__add_compiler_option("-O3")
                 self.__add_compiler_option("-fomit-frame-pointer")
+                self.__add_compiler_option("-D_WCHAR_T_DEFINED")
                 # Don't include debug symbols unless debugging
                 self.__remove_compiler_option("-g")
                 # Don't include profiling information (incompatible with -fomit-frame-pointer)
@@ -157,7 +158,7 @@
             self.compiler.include_dirs.insert(0, "src/inc-msvc/")
 
         # Detect libgmp and don't build _fastmath if it is missing.
-        lib_dirs = self.compiler.library_dirs + ['/lib', '/usr/lib']
+        lib_dirs = self.compiler.library_dirs + ['/lib', '/usr/lib', '%%LOCALBASE%%/lib']
         if not (self.compiler.find_library_file(lib_dirs, 'gmp')):
             print >>sys.stderr, "warning: GMP library not found; Not building Crypto.PublicKey._fastmath."
             self.__remove_extensions(["Crypto.PublicKey._fastmath"])
@@ -264,6 +265,7 @@
             Extension("Crypto.PublicKey._fastmath",
                       include_dirs=['src/'],
                       libraries=['gmp'],
+                      library_dirs=['%%LOCALBASE%%/lib'],
                       sources=["src/_fastmath.c"]),
 
             # Hash functions
