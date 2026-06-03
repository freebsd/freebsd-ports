--- r10k.gemspec.orig	2025-09-04 00:52:11 UTC
+++ r10k.gemspec
@@ -21,7 +21,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<colored2>.freeze, ["~> 4.0".freeze])
+  s.add_runtime_dependency(%q<colored2>.freeze, [">= 3.0", "< 5.0".freeze])
   s.add_runtime_dependency(%q<cri>.freeze, [">= 2.15.10".freeze])
   s.add_runtime_dependency(%q<log4r>.freeze, ["= 1.1.10".freeze])
   s.add_runtime_dependency(%q<multi_json>.freeze, ["~> 1.10".freeze])
