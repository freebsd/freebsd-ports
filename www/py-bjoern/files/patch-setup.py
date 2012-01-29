--- setup.py.orig	2011-04-23 23:23:14.000000000 +0200
+++ setup.py	2011-10-23 17:12:46.000000000 +0200
@@ -8,8 +8,9 @@
 bjoern_extension = Extension(
     'bjoern',
     sources       = SOURCE_FILES,
-    libraries     = ['ev'],
-    include_dirs  = ['http-parser'],
+    library_dirs  = ['%%LOCALBASE%%/lib'],
+    libraries     = ['c', 'ev'],
+    include_dirs  = ['/usr/include', '%%LOCALBASE%%/include', 'http-parser'],
     define_macros = [('WANT_SENDFILE', '1'),
                      ('WANT_SIGINT_HANDLING', '1')],
     extra_compile_args = ['-std=c99', '-fno-strict-aliasing', '-Wall',
