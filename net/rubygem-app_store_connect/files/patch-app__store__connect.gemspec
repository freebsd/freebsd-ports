--- app_store_connect.gemspec.orig	2023-01-30 22:24:51 UTC
+++ app_store_connect.gemspec
@@ -20,7 +20,7 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<activesupport>.freeze, [">= 6.0.0"])
-  s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.4", "<= 2.5.0"])
+  s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.4"])
   s.add_development_dependency(%q<bundler>.freeze, [">= 0"])
   s.add_development_dependency(%q<factory_bot>.freeze, ["~> 6.2.1"])
   s.add_development_dependency(%q<guard-rspec>.freeze, ["~> 4.7.3"])
