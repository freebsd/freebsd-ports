--- r10k.gemspec.orig	2023-08-04 23:21:25 UTC
+++ r10k.gemspec
@@ -25,7 +25,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<cri>.freeze, [">= 2.15.10"])
   s.add_runtime_dependency(%q<log4r>.freeze, ["= 1.1.10"])
   s.add_runtime_dependency(%q<multi_json>.freeze, ["~> 1.10"])
-  s.add_runtime_dependency(%q<puppet_forge>.freeze, [">= 2.3.0", "< 4.0.0"])
+  s.add_runtime_dependency(%q<puppet_forge>.freeze, ">= 2.3.0")
   s.add_runtime_dependency(%q<gettext-setup>.freeze, [">= 0.24", "< 2.0.0"])
   s.add_runtime_dependency(%q<fast_gettext>.freeze, [">= 1.1.0", "< 3.0.0"])
   s.add_runtime_dependency(%q<gettext>.freeze, [">= 3.0.2", "< 4.0.0"])
