--- kas-grpc.gemspec.orig	2023-01-05 23:45:07 UTC
+++ kas-grpc.gemspec
@@ -18,6 +18,6 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.0"])
+  s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
 end
 
