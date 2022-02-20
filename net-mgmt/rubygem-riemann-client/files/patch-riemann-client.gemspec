--- riemann-client.gemspec.orig	2021-10-25 13:35:50 UTC
+++ riemann-client.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
   if s.respond_to? :add_runtime_dependency then
     s.add_development_dependency(%q<bundler>.freeze, [">= 1.3"])
     s.add_development_dependency(%q<bacon>.freeze, [">= 0"])
-    s.add_runtime_dependency(%q<beefcake>.freeze, [">= 0.3.5", "<= 1.0.0"])
+    s.add_runtime_dependency(%q<beefcake>.freeze, [">= 1.2.0"])
     s.add_runtime_dependency(%q<trollop>.freeze, [">= 1.16.2"])
     s.add_runtime_dependency(%q<mtrc>.freeze, [">= 0.0.4"])
   else
