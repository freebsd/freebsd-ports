--- src/uharfbuzz/_harfbuzz.cpp.orig	2022-03-22 22:30:14 UTC
+++ src/uharfbuzz/_harfbuzz.cpp
@@ -30,14 +30,12 @@
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
-            "harfbuzz/src/hb-subset-repacker.cc"
         ]
     },
     "module_name": "uharfbuzz._harfbuzz"
