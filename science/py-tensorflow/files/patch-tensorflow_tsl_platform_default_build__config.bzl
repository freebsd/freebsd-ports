--- tensorflow/tsl/platform/default/build_config.bzl.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/tsl/platform/default/build_config.bzl
@@ -401,13 +401,6 @@ def py_proto_library(
         # is not explicitly listed in py_libs. Instead, host system is assumed to
         # have grpc installed.
 
-    genproto_deps = []
-    for dep in deps:
-        if dep != "@com_google_protobuf//:protobuf_python":
-            genproto_deps.append(dep + "_genproto")
-        else:
-            genproto_deps.append("@com_google_protobuf//:well_known_types_py_pb2_genproto")
-
     proto_gen(
         name = name + "_genproto",
         srcs = srcs,
@@ -418,7 +411,7 @@ def py_proto_library(
         plugin_language = "grpc",
         protoc = protoc,
         visibility = ["//visibility:public"],
-        deps = genproto_deps,
+        deps = [s + "_genproto" for s in deps],
     )
 
     if default_runtime and not default_runtime in py_libs + deps:
