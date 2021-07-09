--- tensorflow/tensorflow.bzl.orig	2021-01-04 20:18:42 UTC
+++ tensorflow/tensorflow.bzl
@@ -289,6 +289,7 @@ def tf_copts(
             "-Iexternal/gemmlowp",
             "-Wno-sign-compare",
             "-ftemplate-depth=900",
+	    "-I%%LOCALBASE%%/include",
         ]) +
         (if_not_windows(["-fno-exceptions"]) if not allow_exceptions else []) +
         if_cuda(["-DGOOGLE_CUDA=1"]) +
@@ -628,7 +629,7 @@ def tf_cc_binary(
                 ],
             ),
             data = depset(data + added_data_deps),
-            linkopts = linkopts + _rpath_linkopts(name_os),
+	    linkopts = linkopts + ["-lexecinfo", "-lgpr"] + _rpath_linkopts(name),
             visibility = visibility,
             **kwargs
         )
@@ -693,7 +694,7 @@ def tf_gen_op_wrapper_cc(
     tf_cc_binary(
         name = tool,
         copts = tf_copts(),
-        linkopts = if_not_windows(["-lm", "-Wl,-ldl"]),
+        linkopts = if_not_windows(["-lm", "-Wl, -lexecinfo"]),
         linkstatic = 1,  # Faster to link this one-time-use binary dynamically
         deps = [op_gen] + deps,
     )
@@ -878,7 +879,7 @@ def tf_gen_op_wrapper_py(
     tf_cc_binary(
         name = tool_name,
         copts = tf_copts(),
-        linkopts = if_not_windows(["-lm", "-Wl,-ldl"]) + cc_linkopts,
+        linkopts = if_not_windows(["-L%%LOCALBASE%%/lib", "-lm", "-Wl, -lexecinfo"]) + cc_linkopts,
         linkstatic = 1,  # Faster to link this one-time-use binary dynamically
         visibility = [clean_dep("//tensorflow:internal")],
         deps = ([
@@ -992,8 +993,9 @@ def tf_cc_test(
             "//conditions:default": [
                 "-lpthread",
                 "-lm",
+		"-lexecinfo",
             ],
-        }) + linkopts + _rpath_linkopts(name),
+        }) + linkopts + ["-lexecinfo"] + _rpath_linkopts(name),
         deps = deps + tf_binary_dynamic_kernel_deps(kernels) + if_mkl_ml(
             [
                 clean_dep("//third_party/mkl:intel_binary_blob"),
@@ -1140,7 +1142,7 @@ def tf_gpu_only_cc_test(
         ]) + if_rocm_is_configured([
             clean_dep("//tensorflow/core:gpu_lib"),
         ]),
-        linkopts = if_not_windows(["-lpthread", "-lm"]) + linkopts + _rpath_linkopts(name),
+        linkopts = if_not_windows(["-lpthread", "-lm", "-lexecinfo",]) + linkopts + _rpath_linkopts(name),
         linkstatic = linkstatic or select({
             # cc_tests with ".so"s in srcs incorrectly link on Darwin
             # unless linkstatic=1.
@@ -1820,6 +1822,7 @@ def tf_custom_op_library(name, srcs = [], gpu_srcs = [
         linkopts = linkopts + select({
             "//conditions:default": [
                 "-lm",
+		"-lexecinfo",
             ],
             clean_dep("//tensorflow:windows"): [],
             clean_dep("//tensorflow:macos"): [],
