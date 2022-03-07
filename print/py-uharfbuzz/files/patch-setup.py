--- setup.py.orig	2022-02-08 07:41:12 UTC
+++ setup.py
@@ -39,8 +39,8 @@ if platform.system() == 'Darwin':
 extension = Extension(
     'uharfbuzz._harfbuzz',
     define_macros=define_macros,
-    include_dirs=['harfbuzz/src'],
-    sources=['src/uharfbuzz/_harfbuzz.pyx', 'harfbuzz/src/harfbuzz.cc'],
+    include_dirs=['%%LOCALBASE%%/include/harfbuzz'],
+    sources=['src/uharfbuzz/_harfbuzz.pyx'],
     language='c++',
     libraries=libraries,
     extra_compile_args=extra_compile_args,
