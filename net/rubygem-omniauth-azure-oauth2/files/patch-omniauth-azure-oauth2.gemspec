--- omniauth-azure-oauth2.gemspec.orig	2022-08-12 07:15:37 UTC
+++ omniauth-azure-oauth2.gemspec
@@ -22,13 +22,13 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.0"])
+    s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.0"])
     s.add_runtime_dependency(%q<jwt>.freeze, [">= 1.0", "< 3.0"])
     s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.4"])
     s.add_development_dependency(%q<rspec>.freeze, [">= 2.14.0"])
     s.add_development_dependency(%q<rake>.freeze, [">= 0"])
   else
-    s.add_dependency(%q<omniauth>.freeze, ["~> 1.0"])
+    s.add_dependency(%q<omniauth>.freeze, [">= 1.0"])
     s.add_dependency(%q<jwt>.freeze, [">= 1.0", "< 3.0"])
     s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.4"])
     s.add_dependency(%q<rspec>.freeze, [">= 2.14.0"])
