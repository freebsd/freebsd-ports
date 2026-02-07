--- origami.gemspec.orig	2024-10-27 10:40:09 UTC
+++ origami.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<colorize>.freeze, ["~> 0.7".freeze])
+  s.add_runtime_dependency(%q<colorize>.freeze, [">= 0.7".freeze])
   s.add_development_dependency(%q<minitest>.freeze, ["~> 5.0".freeze])
 end
 
