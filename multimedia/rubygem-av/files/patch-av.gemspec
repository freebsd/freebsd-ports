--- av.gemspec.orig	2024-02-27 16:44:30 UTC
+++ av.gemspec
@@ -24,6 +24,6 @@ Gem::Specification.new do |s|
   s.add_development_dependency(%q<rake>.freeze, [">= 0".freeze])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0.0".freeze])
   s.add_development_dependency(%q<coveralls>.freeze, [">= 0".freeze])
-  s.add_runtime_dependency(%q<cocaine>.freeze, ["~> 0.5.3".freeze])
+  s.add_runtime_dependency(%q<cocaine>.freeze, [">= 0.5.3".freeze])
 end
 
