--- third_party/systemlibs/protobuf.BUILD.orig	2022-09-01 05:13:59 UTC
+++ third_party/systemlibs/protobuf.BUILD
@@ -61,19 +61,19 @@ genrule(
 
 cc_library(
     name = "protobuf",
-    linkopts = ["-lprotobuf"],
+    linkopts = ["-L%%LOCALBASE%%/lib", "-lprotobuf"],
     visibility = ["//visibility:public"],
 )
 
 cc_library(
     name = "protobuf_headers",
-    linkopts = ["-lprotobuf"],
+    linkopts = ["-L%%LOCALBASE%%/lib", "-lprotobuf"],
     visibility = ["//visibility:public"],
 )
 
 cc_library(
     name = "protoc_lib",
-    linkopts = ["-lprotoc"],
+    linkopts = ["-L%%LOCALBASE%%/lib", "-lprotoc"],
     visibility = ["//visibility:public"],
 )
 
