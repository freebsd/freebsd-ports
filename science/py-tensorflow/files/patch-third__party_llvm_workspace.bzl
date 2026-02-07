--- third_party/llvm/workspace.bzl.orig	2023-09-12 16:46:28 UTC
+++ third_party/llvm/workspace.bzl
@@ -21,6 +21,7 @@ def repo(name):
             "//third_party/llvm:build.patch",
             "//third_party/llvm:mathextras.patch",
             "//third_party/llvm:zstd.patch",
+            "//third_party:fix-environ.patch"
         ],
         link_files = {"//third_party/llvm:run_lit.sh": "mlir/run_lit.sh"},
     )
