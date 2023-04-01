--- tensorflow/lite/build_def.bzl.orig	2023-03-30 17:56:40.338369000 +0200
+++ tensorflow/lite/build_def.bzl	2023-03-30 17:56:50.244995000 +0200
@@ -172,6 +172,7 @@
         ],
         clean_dep("//tensorflow:windows"): [],
         "//conditions:default": [
+            "-Wl,--undefined-version",
             "-Wl,--version-script,$(location {})".format(linkscript),
             "-Wl,-soname," + name,
         ],
