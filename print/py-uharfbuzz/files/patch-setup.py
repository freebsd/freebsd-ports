--- setup.py.orig	2023-03-13 09:18:30 UTC
+++ setup.py
@@ -39,12 +39,8 @@ if platform.system() == "Darwin":
 extension = Extension(
     "uharfbuzz._harfbuzz",
     define_macros=define_macros,
-    include_dirs=["harfbuzz/src"],
+    include_dirs=["%%LOCALBASE%%/include/harfbuzz"],
     sources=[
-        "harfbuzz/src/harfbuzz-subset.cc",
-        "harfbuzz/src/hb-coretext.cc",
-        "harfbuzz/src/hb-directwrite.cc",
-        "harfbuzz/src/hb-uniscribe.cc",
         "src/uharfbuzz/_harfbuzz.pyx",
     ],
     language="c++",
