--- r10k.gemspec.orig	2023-02-27 23:53:06 UTC
+++ r10k.gemspec
@@ -25,11 +25,11 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<cri>.freeze, [">= 2.15.10"])
   s.add_runtime_dependency(%q<log4r>.freeze, ["= 1.1.10"])
   s.add_runtime_dependency(%q<multi_json>.freeze, ["~> 1.10"])
-  s.add_runtime_dependency(%q<puppet_forge>.freeze, [">= 2.3.0", "< 4.0.0"])
+  s.add_runtime_dependency(%q<puppet_forge>.freeze, ">= 2.3.0")
   s.add_runtime_dependency(%q<gettext-setup>.freeze, [">= 0.24", "< 2.0.0"])
   s.add_runtime_dependency(%q<fast_gettext>.freeze, [">= 1.1.0", "< 3.0.0"])
   s.add_runtime_dependency(%q<gettext>.freeze, [">= 3.0.2", "< 4.0.0"])
-  s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2.3"])
+  s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2"])
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.9"])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.1"])
   s.add_development_dependency(%q<rake>.freeze, [">= 0"])
