--- riemann-tools.gemspec.orig	2021-10-27 12:01:10 UTC
+++ riemann-tools.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<riemann-client>.freeze, ["~> 0.2", ">= 0.2.6"])
     s.add_runtime_dependency(%q<optimist>.freeze, ["~> 3.0", ">= 3.0.0"])
-    s.add_runtime_dependency(%q<json>.freeze, ["~> 1.8"])
+    s.add_runtime_dependency(%q<json>.freeze, [">= 1.8"])
   else
     s.add_dependency(%q<riemann-client>.freeze, ["~> 0.2", ">= 0.2.6"])
     s.add_dependency(%q<optimist>.freeze, ["~> 3.0", ">= 3.0.0"])
