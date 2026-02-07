--- omniauth-dingtalk-oauth2.gemspec.orig	2024-02-27 17:54:49 UTC
+++ omniauth-dingtalk-oauth2.gemspec
@@ -21,7 +21,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7".freeze])
+  s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, [">= 1.7".freeze])
   s.add_development_dependency(%q<rake>.freeze, ["~> 12.0".freeze])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0".freeze])
 end
