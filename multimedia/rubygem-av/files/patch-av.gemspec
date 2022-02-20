--- av.gemspec.orig	2021-10-27 12:01:07 UTC
+++ av.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<rake>.freeze, [">= 0"])
     s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0.0"])
     s.add_development_dependency(%q<coveralls>.freeze, [">= 0"])
-    s.add_runtime_dependency(%q<cocaine>.freeze, ["~> 0.5.3"])
+    s.add_runtime_dependency(%q<cocaine>.freeze, [">= 0.5.3"])
   else
     s.add_dependency(%q<bundler>.freeze, ["~> 1.6"])
     s.add_dependency(%q<rake>.freeze, [">= 0"])
