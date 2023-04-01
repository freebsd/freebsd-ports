--- tensorflow/tensorflow.bzl.orig	2023-03-30 17:54:35.641567000 +0200
+++ tensorflow/tensorflow.bzl	2023-03-30 17:56:12.747346000 +0200
@@ -2305,6 +2305,7 @@
         ],
         clean_dep("//tensorflow:windows"): [],
         "//conditions:default": [
+            "-Wl,--undefined-version",
             "-Wl,--version-script",
             "$(location %s.lds)" % vscriptname,
         ],
@@ -2975,6 +2976,7 @@
                     "/ignore:4070",
                 ] if win_def_file else [],
                 "//conditions:default": [
+                    "-Wl,--undefined-version",
                     "-Wl,--version-script",
                     "$(location %s)" % version_script_file,
                 ],
@@ -3035,6 +3037,7 @@
                 ],
                 clean_dep("//tensorflow:windows"): [],
                 "//conditions:default": [
+                    "-Wl,--undefined-version",
                     "-Wl,--version-script",
                     "$(location %s)" % version_script_file,
                 ],
