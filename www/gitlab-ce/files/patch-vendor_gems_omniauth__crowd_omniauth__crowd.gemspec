--- vendor/gems/omniauth_crowd/omniauth_crowd.gemspec.orig	2022-08-12 14:59:10 UTC
+++ vendor/gems/omniauth_crowd/omniauth_crowd.gemspec
@@ -15,7 +15,7 @@ Gem::Specification.new do |gem|
   gem.require_paths = ["lib"]
   gem.version = OmniAuth::Crowd::VERSION
 
-  gem.add_runtime_dependency 'omniauth', '~> 1.0', '< 3'
+  gem.add_runtime_dependency 'omniauth', '>= 1.0', '< 3'
   gem.add_runtime_dependency 'nokogiri', '>= 1.4.4'
   gem.add_runtime_dependency 'activesupport', '>= 0'
   gem.add_development_dependency(%q<rack>, [">= 0"])
