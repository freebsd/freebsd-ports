--- r10k.gemspec.orig	2023-01-06 04:20:47 UTC
+++ r10k.gemspec
@@ -29,7 +29,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<gettext-setup>.freeze, ["~> 0.24"])
   s.add_runtime_dependency(%q<fast_gettext>.freeze, [">= 1.1.0", "< 3.0.0"])
   s.add_runtime_dependency(%q<gettext>.freeze, [">= 3.0.2", "< 4.0.0"])
-  s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2.3"])
+  s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2"])
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.9"])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.1"])
   s.add_development_dependency(%q<rake>.freeze, [">= 0"])
