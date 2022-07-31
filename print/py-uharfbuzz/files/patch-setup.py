--- setup.py.orig	2022-07-31 12:39:52 UTC
+++ setup.py
@@ -39,12 +39,9 @@ extension = Extension(
 extension = Extension(
     'uharfbuzz._harfbuzz',
     define_macros=define_macros,
-    include_dirs=['harfbuzz/src'],
+    include_dirs=['%%LOCALBASE%%/include/harfbuzz'],
     sources=[
         'src/uharfbuzz/_harfbuzz.pyx',
-        'harfbuzz/src/harfbuzz.cc',
-        'harfbuzz/src/hb-subset-repacker.cc',
-        'harfbuzz/src/graph/gsubgpos-context.cc',
         'src/uharfbuzz/_draw_test_funcs.cc',
     ],
     language='c++',
