--- omniauth-salesforce.gemspec.orig	2023-01-05 23:53:18 UTC
+++ omniauth-salesforce.gemspec
@@ -20,7 +20,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 3
 
-  s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.0"])
+  s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.0"])
   s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.0"])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 2.7"])
   s.add_development_dependency(%q<rack-test>.freeze, [">= 0"])
