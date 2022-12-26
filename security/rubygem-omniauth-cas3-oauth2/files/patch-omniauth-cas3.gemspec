--- omniauth-cas3.gemspec.orig	2023-01-06 01:42:01 UTC
+++ omniauth-cas3.gemspec
@@ -19,7 +19,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.2"])
+  s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.2"])
   s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1.7", ">= 1.7.1"])
   s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.3"])
   s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
