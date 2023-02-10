--- omniauth-facebook.gemspec.orig	2023-01-05 23:49:02 UTC
+++ omniauth-facebook.gemspec
@@ -19,7 +19,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.2"])
+  s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, [">= 1.2"])
   s.add_development_dependency(%q<minitest>.freeze, [">= 0"])
   s.add_development_dependency(%q<mocha>.freeze, [">= 0"])
   s.add_development_dependency(%q<rake>.freeze, [">= 0"])
