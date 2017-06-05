--- truncato.gemspec.orig	2017-06-05 05:21:12 UTC
+++ truncato.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1.7.0"])
+      s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.7.0"])
       s.add_runtime_dependency(%q<htmlentities>.freeze, ["~> 4.3.1"])
       s.add_development_dependency(%q<rspec>.freeze, ["~> 2.14.1"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.1.1"])
