--- doorkeeper-openid_connect.gemspec.orig	2023-01-06 01:38:46 UTC
+++ doorkeeper-openid_connect.gemspec
@@ -20,7 +20,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<doorkeeper>.freeze, [">= 5.2", "< 5.5"])
+  s.add_runtime_dependency(%q<doorkeeper>.freeze, [">= 5.2", "< 5.6"])
   s.add_runtime_dependency(%q<json-jwt>.freeze, [">= 1.11.0"])
   s.add_development_dependency(%q<conventional-changelog>.freeze, ["~> 1.2"])
   s.add_development_dependency(%q<factory_bot>.freeze, [">= 0"])
