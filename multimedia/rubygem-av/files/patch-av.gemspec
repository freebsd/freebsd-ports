--- av.gemspec.orig	2023-01-05 21:45:12 UTC
+++ av.gemspec
@@ -24,6 +24,6 @@ Gem::Specification.new do |s|
   s.add_development_dependency(%q<rake>.freeze, [">= 0"])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0.0"])
   s.add_development_dependency(%q<coveralls>.freeze, [">= 0"])
-  s.add_runtime_dependency(%q<cocaine>.freeze, ["~> 0.5.3"])
+  s.add_runtime_dependency(%q<cocaine>.freeze, [">= 0.5.3"])
 end
 
