--- spamcheck.gemspec.orig	2023-01-05 23:55:10 UTC
+++ spamcheck.gemspec
@@ -19,6 +19,6 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.0"])
+  s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
 end
 
