--- setup.py.orig	Sat Aug 14 01:44:47 2004
+++ setup.py	Fri Oct  1 21:21:45 2004
@@ -116,13 +116,14 @@
         build_ext.build_extensions(self)
 
     def detect_modules (self):
-        lib_dirs = self.compiler.library_dirs + ['/lib', '/usr/lib']
-        inc_dirs = self.compiler.include_dirs + ['/usr/include']
+        lib_dirs = self.compiler.library_dirs + ['/lib', '/usr/lib', '%%LOCALBASE%%/lib']
+        inc_dirs = self.compiler.include_dirs + ['/usr/include', '%%LOCALBASE%%/include']
         exts = []
         if (self.compiler.find_library_file(lib_dirs, 'gmp')):
             exts.append(Extension("Crypto.PublicKey._fastmath",
-                                  include_dirs=['src/'],
+                                  include_dirs=['src/', '%%LOCALBASE%%/include'],
                                   libraries=['gmp'],
+				  library_dirs=['%%LOCALBASE%%/lib'],
                                   sources=["src/_fastmath.c"]))
         self.extensions += exts
 
