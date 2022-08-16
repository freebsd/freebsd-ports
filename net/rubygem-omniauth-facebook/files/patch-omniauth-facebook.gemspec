--- omniauth-facebook.gemspec.orig	2022-08-12 05:57:21 UTC
+++ omniauth-facebook.gemspec
@@ -22,12 +22,12 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.2"])
+    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, [">= 1.2"])
     s.add_development_dependency(%q<minitest>.freeze, [">= 0"])
     s.add_development_dependency(%q<mocha>.freeze, [">= 0"])
     s.add_development_dependency(%q<rake>.freeze, [">= 0"])
   else
-    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.2"])
+    s.add_dependency(%q<omniauth-oauth2>.freeze, [">= 1.2"])
     s.add_dependency(%q<minitest>.freeze, [">= 0"])
     s.add_dependency(%q<mocha>.freeze, [">= 0"])
     s.add_dependency(%q<rake>.freeze, [">= 0"])
