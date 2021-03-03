--- doorkeeper-openid_connect.gemspec.orig	2021-02-22 17:31:34 UTC
+++ doorkeeper-openid_connect.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<doorkeeper>.freeze, [">= 5.2", "< 5.5"])
+      s.add_runtime_dependency(%q<doorkeeper>.freeze, [">= 5.2", "< 5.6"])
       s.add_runtime_dependency(%q<json-jwt>.freeze, [">= 1.11.0"])
       s.add_development_dependency(%q<conventional-changelog>.freeze, ["~> 1.2"])
       s.add_development_dependency(%q<factory_bot>.freeze, [">= 0"])
