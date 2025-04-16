--- gitlab-secret_detection.gemspec.orig	2025-04-16 06:47:28 UTC
+++ gitlab-secret_detection.gemspec
@@ -21,7 +21,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.63.0".freeze])
+  s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.63".freeze])
   s.add_runtime_dependency(%q<grpc_reflection>.freeze, ["~> 0.1".freeze])
   s.add_runtime_dependency(%q<grpc-tools>.freeze, ["~> 1.63".freeze])
   s.add_runtime_dependency(%q<parallel>.freeze, ["~> 1".freeze])
