--- choria-mcorpc-support.gemspec.orig	2023-01-06 04:17:25 UTC
+++ choria-mcorpc-support.gemspec
@@ -21,6 +21,6 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<systemu>.freeze, ["~> 2.6", ">= 2.6.4"])
-  s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.7.0"])
+  s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.8.0"])
 end
 
