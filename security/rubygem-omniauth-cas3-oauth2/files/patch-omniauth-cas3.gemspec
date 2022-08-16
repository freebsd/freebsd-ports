--- omniauth-cas3.gemspec.orig	2022-08-12 07:04:12 UTC
+++ omniauth-cas3.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<omniauth>.freeze, ["~> 1.2"])
+    s.add_runtime_dependency(%q<omniauth>.freeze, [">= 1.2"])
     s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1.7", ">= 1.7.1"])
     s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.3"])
     s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
@@ -31,7 +31,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<rack-test>.freeze, ["~> 0.6"])
     s.add_development_dependency(%q<awesome_print>.freeze, [">= 0"])
   else
-    s.add_dependency(%q<omniauth>.freeze, ["~> 1.2"])
+    s.add_dependency(%q<omniauth>.freeze, [">= 1.2"])
     s.add_dependency(%q<nokogiri>.freeze, ["~> 1.7", ">= 1.7.1"])
     s.add_dependency(%q<addressable>.freeze, ["~> 2.3"])
     s.add_dependency(%q<rake>.freeze, ["~> 10.0"])
