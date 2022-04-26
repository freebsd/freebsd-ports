--- setup.py.orig	2022-03-22 22:29:38 UTC
+++ setup.py
@@ -39,11 +39,9 @@ if platform.system() == 'Darwin':
 extension = Extension(
     'uharfbuzz._harfbuzz',
     define_macros=define_macros,
-    include_dirs=['harfbuzz/src'],
+    include_dirs=['%%LOCALBASE%%/include/harfbuzz'],
     sources=[
         'src/uharfbuzz/_harfbuzz.pyx',
-        'harfbuzz/src/harfbuzz.cc',
-        'harfbuzz/src/hb-subset-repacker.cc',
     ],
     language='c++',
     libraries=libraries,
