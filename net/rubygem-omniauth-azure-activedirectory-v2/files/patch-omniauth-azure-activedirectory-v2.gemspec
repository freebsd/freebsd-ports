--- omniauth-azure-activedirectory-v2.gemspec.orig	2022-08-09 15:06:21 UTC
+++ omniauth-azure-activedirectory-v2.gemspec
@@ -24,9 +24,9 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
+    s.add_runtime_dependency(%q<omniauth-oauth2>.freeze, [">= 1.7"])
   else
-    s.add_dependency(%q<omniauth-oauth2>.freeze, ["~> 1.7"])
+    s.add_dependency(%q<omniauth-oauth2>.freeze, [">= 1.7"])
   end
 end
 
