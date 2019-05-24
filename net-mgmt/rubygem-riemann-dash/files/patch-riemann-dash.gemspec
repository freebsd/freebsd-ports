--- riemann-dash.gemspec.orig	2018-12-25 17:47:00 UTC
+++ riemann-dash.gemspec
@@ -24,23 +24,10 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<erubis>.freeze, [">= 2.7.0"])
-      s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4.5"])
+      s.add_runtime_dependency(%q<sinatra>.freeze, [">= 1.4.5"])
       s.add_runtime_dependency(%q<sass>.freeze, [">= 3.1.14"])
-      s.add_runtime_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
-      s.add_runtime_dependency(%q<multi_json>.freeze, ["= 1.3.6"])
-    else
-      s.add_dependency(%q<erubis>.freeze, [">= 2.7.0"])
-      s.add_dependency(%q<sinatra>.freeze, ["~> 1.4.5"])
-      s.add_dependency(%q<sass>.freeze, [">= 3.1.14"])
-      s.add_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
-      s.add_dependency(%q<multi_json>.freeze, ["= 1.3.6"])
+      s.add_runtime_dependency(%q<multi_json>.freeze, [">= 1.3.6"])
     end
-  else
-    s.add_dependency(%q<erubis>.freeze, [">= 2.7.0"])
-    s.add_dependency(%q<sinatra>.freeze, ["~> 1.4.5"])
-    s.add_dependency(%q<sass>.freeze, [">= 3.1.14"])
-    s.add_dependency(%q<webrick>.freeze, ["~> 1.3.1"])
-    s.add_dependency(%q<multi_json>.freeze, ["= 1.3.6"])
   end
 end
 
