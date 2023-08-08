- workaround for clang++ failure, see https://github.com/llvm/llvm-project/issues/59683

--- include/options.hxx.orig	2022-12-23 21:59:09 UTC
+++ include/options.hxx
@@ -198,7 +198,7 @@ class Options { (public)
     /// Copy constructor
     AttributeType(const AttributeType& other) = default;
     /// Move constructor
-    AttributeType(AttributeType&& other) : Base(std::move(other)) {}
+    AttributeType(AttributeType& other) : Base(std::move(other)) {}
 
     /// Destructor
     ~AttributeType() = default;
