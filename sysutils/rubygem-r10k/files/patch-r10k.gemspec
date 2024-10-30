--- r10k.gemspec.orig	2024-10-30 18:54:06 UTC
+++ r10k.gemspec
@@ -25,10 +25,10 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<cri>.freeze, [">= 2.15.10".freeze])
   s.add_runtime_dependency(%q<log4r>.freeze, ["= 1.1.10".freeze])
   s.add_runtime_dependency(%q<multi_json>.freeze, ["~> 1.10".freeze])
-  s.add_runtime_dependency(%q<puppet_forge>.freeze, [">= 4.1".freeze, "< 6".freeze])
+  s.add_runtime_dependency(%q<puppet_forge>.freeze, [">= 4.1".freeze])
   s.add_runtime_dependency(%q<gettext-setup>.freeze, [">= 0.24".freeze, "< 2.0".freeze])
   s.add_runtime_dependency(%q<jwt>.freeze, [">= 2.2.3".freeze, "< 3".freeze])
-  s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.9".freeze])
+  s.add_runtime_dependency(%q<minitar>.freeze, [">= 0.9".freeze])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.1".freeze])
   s.add_development_dependency(%q<rake>.freeze, [">= 0".freeze])
   s.add_development_dependency(%q<yard>.freeze, ["~> 0.9.11".freeze])
