--- src/uharfbuzz/_harfbuzz.cpp.orig	2023-03-13 09:19:32 UTC
+++ src/uharfbuzz/_harfbuzz.cpp
@@ -30,16 +30,12 @@
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
-            "harfbuzz/src/harfbuzz-subset.cc",
-            "harfbuzz/src/hb-coretext.cc",
-            "harfbuzz/src/hb-directwrite.cc",
-            "harfbuzz/src/hb-uniscribe.cc"
         ]
     },
     "module_name": "uharfbuzz._harfbuzz"
