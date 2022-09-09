--- src/uharfbuzz/_harfbuzz.cpp.orig	2022-07-31 07:40:22 UTC
+++ src/uharfbuzz/_harfbuzz.cpp
@@ -30,15 +30,12 @@
             "-std=c++11"
         ],
         "include_dirs": [
-            "harfbuzz/src"
+            "%%LOCALBASE%%/include/harfbuzz"
         ],
         "language": "c++",
         "name": "uharfbuzz._harfbuzz",
         "sources": [
             "src/uharfbuzz/_harfbuzz.pyx",
-            "harfbuzz/src/harfbuzz.cc",
-            "harfbuzz/src/hb-subset-repacker.cc",
-            "harfbuzz/src/graph/gsubgpos-context.cc",
             "src/uharfbuzz/_draw_test_funcs.cc"
         ]
     },
