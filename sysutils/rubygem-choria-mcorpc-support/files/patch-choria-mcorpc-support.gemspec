--- choria-mcorpc-support.gemspec.orig	2021-08-24 19:12:29 UTC
+++ choria-mcorpc-support.gemspec
@@ -23,14 +23,14 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<systemu>.freeze, ["~> 2.6", ">= 2.6.4"])
-      s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.7.0"])
+      s.add_runtime_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.8.0"])
     else
       s.add_dependency(%q<systemu>.freeze, ["~> 2.6", ">= 2.6.4"])
-      s.add_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.7.0"])
+      s.add_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.8.0"])
     end
   else
     s.add_dependency(%q<systemu>.freeze, ["~> 2.6", ">= 2.6.4"])
-    s.add_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.7.0"])
+    s.add_dependency(%q<nats-pure>.freeze, ["~> 0.6", "< 0.8.0"])
   end
 end
 
