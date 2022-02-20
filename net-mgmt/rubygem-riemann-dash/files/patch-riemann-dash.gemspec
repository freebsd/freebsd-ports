--- riemann-dash.gemspec.orig	2021-11-01 19:43:43 UTC
+++ riemann-dash.gemspec
@@ -24,10 +24,9 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<erubis>.freeze, [">= 2.7.0"])
-    s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4.5"])
+    s.add_runtime_dependency(%q<sinatra>.freeze, [">= 1.4.5"])
     s.add_runtime_dependency(%q<sass>.freeze, [">= 3.1.14"])
-    s.add_runtime_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
-    s.add_runtime_dependency(%q<multi_json>.freeze, ["= 1.3.6"])
+    s.add_runtime_dependency(%q<multi_json>.freeze, [">= 1.3.6"])
   else
     s.add_dependency(%q<erubis>.freeze, [">= 2.7.0"])
     s.add_dependency(%q<sinatra>.freeze, ["~> 1.4.5"])
