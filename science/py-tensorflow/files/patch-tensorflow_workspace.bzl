--- tensorflow/workspace.bzl.orig	2019-07-11 15:46:44.460265000 +0100
+++ tensorflow/workspace.bzl	2019-07-11 15:47:14.104299000 +0100
@@ -346,6 +346,7 @@
         ],
         sha256 = "8ad8c4783bf61ded74527bffb48ed9b54166685e4230386a9ed9b1279e2df5b1",
         build_file = clean_dep("//third_party:enum34.BUILD"),
+	system_build_file = clean_dep("//third_party/systemlibs:enum34.BUILD"),
         strip_prefix = "enum34-1.1.6/enum",
     )
 
