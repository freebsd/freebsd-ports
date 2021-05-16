--- src/uharfbuzz/_harfbuzz.cpp.orig	2021-05-09 03:05:40 UTC
+++ src/uharfbuzz/_harfbuzz.cpp
@@ -18,13 +18,12 @@
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
-            "harfbuzz/src/harfbuzz.cc"
         ]
     },
     "module_name": "uharfbuzz._harfbuzz"
