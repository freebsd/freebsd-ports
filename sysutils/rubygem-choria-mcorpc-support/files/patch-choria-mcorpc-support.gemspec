--- choria-mcorpc-support.gemspec.orig	2024-02-27 16:46:13 UTC
+++ choria-mcorpc-support.gemspec
@@ -21,6 +21,6 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<systemu>.freeze, ["~> 2.6".freeze, ">= 2.6.4".freeze])
-  s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6".freeze, "< 0.7.0".freeze])
+  s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6".freeze, "< 0.8.0".freeze])
 end
 
