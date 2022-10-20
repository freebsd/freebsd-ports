--- vendor/gems/omniauth-gitlab/omniauth-gitlab.gemspec.orig	2022-10-18 19:55:51 UTC
+++ vendor/gems/omniauth-gitlab/omniauth-gitlab.gemspec
@@ -17,7 +17,7 @@ Gem::Specification.new do |gem|
   gem.require_paths = ['lib']
 
   gem.add_dependency 'omniauth', '~> 2.0'
-  gem.add_dependency 'omniauth-oauth2', '~> 1.7.1'
+  gem.add_dependency 'omniauth-oauth2', '~> 1.7'
   gem.add_development_dependency 'rspec', '~> 3.1'
   gem.add_development_dependency 'rspec-its', '~> 1.0'
   gem.add_development_dependency 'simplecov'
