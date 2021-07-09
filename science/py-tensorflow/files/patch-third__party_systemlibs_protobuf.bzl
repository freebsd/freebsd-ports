--- third_party/systemlibs/protobuf.bzl.orig	2021-01-04 20:18:42 UTC
+++ third_party/systemlibs/protobuf.bzl
@@ -76,7 +76,7 @@ def _proto_gen_impl(ctx):
     source_dir = _SourceDir(ctx)
     gen_dir = _GenDir(ctx)
     if source_dir:
-        import_flags = ["-I" + source_dir, "-I" + gen_dir]
+        import_flags = ["-I%%LOCALBASE%%/include", "-I" + source_dir, "-I" + gen_dir]
     else:
         import_flags = ["-I."]
 
