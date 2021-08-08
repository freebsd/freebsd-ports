--- setup.py.orig	2021-07-24 15:45:38 UTC
+++ setup.py
@@ -34,10 +34,10 @@ if platform.system() == 'Darwin':
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
     libraries=libraries,
     extra_compile_args=extra_compile_args,
