--- omniauth-dingtalk-oauth2.gemspec.orig	2022-08-09 16:03:30 UTC
+++ omniauth-dingtalk-oauth2.gemspec
@@ -24,11 +24,11 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
+    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, [">= 1.7"])
     s.add_development_dependency(%q<rake>.freeze, ["~> 12.0"])
     s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0"])
   else
-    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
+    s.add_dependency(%q<omniauth-oauth2>.freeze, [">= 1.7"])
     s.add_dependency(%q<rake>.freeze, ["~> 12.0"])
     s.add_dependency(%q<rspec>.freeze, ["~> 3.0"])
   end
