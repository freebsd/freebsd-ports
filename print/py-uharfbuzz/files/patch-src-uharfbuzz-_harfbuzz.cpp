--- src/uharfbuzz/_harfbuzz.cpp.orig	2022-07-31 12:40:22 UTC
+++ src/uharfbuzz/_harfbuzz.cpp
@@ -36,9 +36,6 @@
         "name": "uharfbuzz._harfbuzz",
         "sources": [
             "src/uharfbuzz/_harfbuzz.pyx",
-            "harfbuzz/src/harfbuzz.cc",
-            "harfbuzz/src/hb-subset-repacker.cc",
-            "harfbuzz/src/graph/gsubgpos-context.cc",
             "src/uharfbuzz/_draw_test_funcs.cc"
         ]
     },
