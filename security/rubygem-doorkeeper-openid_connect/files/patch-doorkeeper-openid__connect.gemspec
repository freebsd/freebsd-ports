--- doorkeeper-openid_connect.gemspec.orig	2021-10-27 12:01:16 UTC
+++ doorkeeper-openid_connect.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<doorkeeper>.freeze, [">= 5.2", "< 5.5"])
+    s.add_runtime_dependency(%q<doorkeeper>.freeze, [">= 5.2", "< 5.6"])
     s.add_runtime_dependency(%q<json-jwt>.freeze, [">= 1.11.0"])
     s.add_development_dependency(%q<conventional-changelog>.freeze, ["~> 1.2"])
     s.add_development_dependency(%q<factory_bot>.freeze, [">= 0"])
