--- tensorflow/core/platform/default/build_config.bzl.orig	2019-07-06 21:55:11.899673000 +0100
+++ tensorflow/core/platform/default/build_config.bzl	2019-07-06 21:56:04.571430000 +0100
@@ -796,9 +796,7 @@
         "//tensorflow:ios": [],
         "//tensorflow:windows": [],
         "//tensorflow:macos": [],
-        "//conditions:default": [
-            "@hwloc",
-        ],
+        "//tensorflow:freebsd": [],
     })
 
 def tf_additional_numa_copts():
