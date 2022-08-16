--- omniauth-gitlab.gemspec.orig	2022-08-12 13:11:26 UTC
+++ omniauth-gitlab.gemspec
@@ -23,14 +23,14 @@ Gem::Specification.new do |s|
 
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 2.0"])
-    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7.1"])
+    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
     s.add_development_dependency(%q<rspec>.freeze, ["~> 3.1"])
     s.add_development_dependency(%q<rspec-its>.freeze, ["~> 1.0"])
     s.add_development_dependency(%q<simplecov>.freeze, [">= 0"])
     s.add_development_dependency(%q<rake>.freeze, [">= 12.0"])
   else
     s.add_dependency(%q<omniauth>.freeze, ["~> 2.0"])
-    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7.1"])
+    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
     s.add_dependency(%q<rspec>.freeze, ["~> 3.1"])
     s.add_dependency(%q<rspec-its>.freeze, ["~> 1.0"])
     s.add_dependency(%q<simplecov>.freeze, [">= 0"])
