--- omniauth-azure-oauth2.gemspec.orig	2023-01-05 23:46:55 UTC
+++ omniauth-azure-oauth2.gemspec
@@ -19,7 +19,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.0"])
+  s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.0"])
   s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.0", "< 3.0"])
   s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.4"])
   s.add_development_dependency(%q<rspec>.freeze, [">= 2.14.0"])
