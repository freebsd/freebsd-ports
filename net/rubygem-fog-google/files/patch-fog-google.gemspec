--- fog-google.gemspec.orig	2022-08-12 13:21:05 UTC
+++ fog-google.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<fog-core>.freeze, ["< 2.3"])
+    s.add_runtime_dependency(%q<fog-core>.freeze, ["< 2.4"])
     s.add_runtime_dependency(%q<fog-json>.freeze, ["~> 1.2"])
     s.add_runtime_dependency(%q<fog-xml>.freeze, ["~> 0.1.0"])
     s.add_runtime_dependency(%q<google-apis-storage_v1>.freeze, ["~> 0.6"])
@@ -44,7 +44,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<vcr>.freeze, [">= 0"])
     s.add_development_dependency(%q<webmock>.freeze, [">= 0"])
   else
-    s.add_dependency(%q<fog-core>.freeze, ["< 2.3"])
+    s.add_dependency(%q<fog-core>.freeze, ["< 2.4"])
     s.add_dependency(%q<fog-json>.freeze, ["~> 1.2"])
     s.add_dependency(%q<fog-xml>.freeze, ["~> 0.1.0"])
     s.add_dependency(%q<google-apis-storage_v1>.freeze, ["~> 0.6"])
