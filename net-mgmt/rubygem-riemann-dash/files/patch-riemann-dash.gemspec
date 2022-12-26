--- riemann-dash.gemspec.orig	2023-01-06 01:30:56 UTC
+++ riemann-dash.gemspec
@@ -21,9 +21,8 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<erubis>.freeze, [">= 2.7.0"])
-  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4.5"])
+  s.add_runtime_dependency(%q<sinatra>.freeze, [">= 1.4.5"])
   s.add_runtime_dependency(%q<sass>.freeze, [">= 3.1.14"])
-  s.add_runtime_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
-  s.add_runtime_dependency(%q<multi_json>.freeze, ["= 1.3.6"])
+  s.add_runtime_dependency(%q<multi_json>.freeze, [">= 1.3.6"])
 end
 
