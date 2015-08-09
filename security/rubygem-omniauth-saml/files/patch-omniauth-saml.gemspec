--- omniauth-saml.gemspec.orig	2015-07-06 11:43:34 UTC
+++ omniauth-saml.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<omniauth>, ["~> 1.1"])
-      s.add_runtime_dependency(%q<ruby-saml>, ["~> 0.8.1"])
+      s.add_runtime_dependency(%q<ruby-saml>, [">= 0.8.1"])
       s.add_development_dependency(%q<rspec>, ["~> 2.8"])
       s.add_development_dependency(%q<simplecov>, ["~> 0.6"])
       s.add_development_dependency(%q<rack-test>, ["~> 0.6"])
