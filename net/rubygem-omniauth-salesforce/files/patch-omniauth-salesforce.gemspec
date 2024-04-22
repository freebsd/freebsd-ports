--- omniauth-salesforce.gemspec.orig	2024-02-27 17:58:34 UTC
+++ omniauth-salesforce.gemspec
@@ -20,7 +20,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 3
 
-  s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.0".freeze])
+  s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.0".freeze])
   s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.0".freeze])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 2.7".freeze])
   s.add_development_dependency(%q<rack-test>.freeze, [">= 0".freeze])
