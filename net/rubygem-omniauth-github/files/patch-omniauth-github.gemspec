--- omniauth-github.gemspec.orig	2022-08-12 14:40:02 UTC
+++ omniauth-github.gemspec
@@ -24,14 +24,14 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 2.0"])
-    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7.1"])
+    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
     s.add_development_dependency(%q<rspec>.freeze, ["~> 3.5"])
     s.add_development_dependency(%q<rack-test>.freeze, [">= 0"])
     s.add_development_dependency(%q<simplecov>.freeze, [">= 0"])
     s.add_development_dependency(%q<webmock>.freeze, [">= 0"])
   else
     s.add_dependency(%q<omniauth>.freeze, ["~> 2.0"])
-    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7.1"])
+    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
     s.add_dependency(%q<rspec>.freeze, ["~> 3.5"])
     s.add_dependency(%q<rack-test>.freeze, [">= 0"])
     s.add_dependency(%q<simplecov>.freeze, [">= 0"])
