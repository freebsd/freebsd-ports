--- choria-mcorpc-support.gemspec.orig	2021-10-25 13:46:23 UTC
+++ choria-mcorpc-support.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<systemu>.freeze, ["~> 2.6", ">= 2.6.4"])
-    s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.7.0"])
+    s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.8.0"])
   else
     s.add_dependency(%q<systemu>.freeze, ["~> 2.6", ">= 2.6.4"])
     s.add_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.7.0"])
