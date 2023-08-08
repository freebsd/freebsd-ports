--- omniauth-dingtalk-oauth2.gemspec.orig	2023-01-06 01:44:14 UTC
+++ omniauth-dingtalk-oauth2.gemspec
@@ -21,7 +21,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
+  s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, [">= 1.7"])
   s.add_development_dependency(%q<rake>.freeze, ["~> 12.0"])
   s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0"])
 end
