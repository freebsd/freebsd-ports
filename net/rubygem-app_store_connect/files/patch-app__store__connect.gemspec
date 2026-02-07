--- app_store_connect.gemspec.orig	2024-02-27 16:42:48 UTC
+++ app_store_connect.gemspec
@@ -20,7 +20,7 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<activesupport>.freeze, [">= 6.0.0".freeze])
-  s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.4".freeze, "<= 2.5.0".freeze])
+  s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.4".freeze])
   s.add_development_dependency(%q<bundler>.freeze, [">= 0".freeze])
   s.add_development_dependency(%q<factory_bot>.freeze, ["~> 6.2.1".freeze])
   s.add_development_dependency(%q<guard-rspec>.freeze, ["~> 4.7.3".freeze])
