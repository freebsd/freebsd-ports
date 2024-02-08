--- omniauth-azure-oauth2.gemspec.orig	2024-02-27 17:52:32 UTC
+++ omniauth-azure-oauth2.gemspec
@@ -19,7 +19,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.0".freeze])
+  s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.0".freeze])
   s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.0".freeze, "< 3.0".freeze])
   s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.4".freeze])
   s.add_development_dependency(%q<rspec>.freeze, [">= 2.14.0".freeze])
