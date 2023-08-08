--- tensorflow/lite/delegates/flex/build_def.bzl.orig	2023-03-30 17:57:26.322444000 +0200
+++ tensorflow/lite/delegates/flex/build_def.bzl	2023-03-30 17:58:45.005163000 +0200
@@ -223,6 +223,7 @@
             "//tensorflow:windows": [],
             "//conditions:default": [
                 "-Wl,-z,defs",
+                "-Wl,--undefined-version",
                 "-Wl,--version-script,$(location //tensorflow/lite/delegates/flex:version_script.lds)",
             ],
         }),
