--- omniauth-salesforce.gemspec.orig	2022-08-12 14:54:54 UTC
+++ omniauth-salesforce.gemspec
@@ -23,14 +23,14 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.0"])
+    s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.0"])
     s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.0"])
     s.add_development_dependency(%q<rspec>.freeze, ["~> 2.7"])
     s.add_development_dependency(%q<rack-test>.freeze, [">= 0"])
     s.add_development_dependency(%q<simplecov>.freeze, [">= 0"])
     s.add_development_dependency(%q<webmock>.freeze, [">= 0"])
   else
-    s.add_dependency(%q<omniauth>.freeze, ["~> 1.0"])
+    s.add_dependency(%q<omniauth>.freeze, [">= 1.0"])
     s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.0"])
     s.add_dependency(%q<rspec>.freeze, ["~> 2.7"])
     s.add_dependency(%q<rack-test>.freeze, [">= 0"])
