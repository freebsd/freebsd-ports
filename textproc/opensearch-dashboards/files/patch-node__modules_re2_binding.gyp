--- node_modules/re2/binding.gyp.orig	2021-07-02 23:30:56 UTC
+++ node_modules/re2/binding.gyp
@@ -45,7 +45,7 @@
         "-Wno-sign-compare",
         "-Wno-unused-parameter",
         "-Wno-missing-field-initializers",
-        "-Wno-cast-function-type",
+        "-Wno-bad-function-cast",
         "-O3",
         "-g"
       ],
@@ -54,7 +54,8 @@
         "NOMINMAX"
       ],
       "include_dirs": [
-        "<!(node -e \"require('nan')\")",
+        "%%WRKSRC%%/node_modules/nan",
+        "%%LOCALBASE%%/include",
         "vendor"
       ],
       "xcode_settings": {
