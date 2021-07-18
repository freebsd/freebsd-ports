--- setup.py.orig	2021-05-09 03:05:20 UTC
+++ setup.py
@@ -28,10 +28,10 @@ if platform.system() == 'Darwin':
     extra_link_args.extend(['-framework', 'ApplicationServices'])
 
 extension = Extension(
-    'uharfbuzz._harfbuzz',
+    'uharfbuzz',
     define_macros=define_macros,
-    include_dirs=['harfbuzz/src'],
-    sources=['src/uharfbuzz/_harfbuzz.pyx', 'harfbuzz/src/harfbuzz.cc'],
+    include_dirs=['%%LOCALBASE%%/include/harfbuzz'],
+    sources=['src/uharfbuzz/_harfbuzz.pyx'],
     language='c++',
     extra_compile_args=extra_compile_args,
     extra_link_args=extra_link_args,
