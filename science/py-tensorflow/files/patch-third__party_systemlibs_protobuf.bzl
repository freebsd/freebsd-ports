--- third_party/systemlibs/protobuf.bzl.orig	2019-07-26 12:28:57.790848000 +0100
+++ third_party/systemlibs/protobuf.bzl	2019-07-26 12:29:42.978059000 +0100
@@ -76,7 +76,7 @@
     source_dir = _SourceDir(ctx)
     gen_dir = _GenDir(ctx)
     if source_dir:
-        import_flags = ["-I" + source_dir, "-I" + gen_dir]
+        import_flags = ["-I%%LOCALBASE%%/include", "-I" + source_dir, "-I" + gen_dir]
     else:
         import_flags = ["-I."]
 
