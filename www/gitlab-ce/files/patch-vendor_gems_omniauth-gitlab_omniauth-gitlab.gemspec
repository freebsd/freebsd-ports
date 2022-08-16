--- vendor/gems/omniauth-gitlab/omniauth-gitlab.gemspec.orig	2022-08-12 14:45:36 UTC
+++ vendor/gems/omniauth-gitlab/omniauth-gitlab.gemspec
@@ -16,8 +16,8 @@ Gem::Specification.new do |gem|
   gem.test_files    = Dir['spec/**/*.rb']
   gem.require_paths = ['lib']
 
-  gem.add_dependency 'omniauth', '~> 1.0'
-  gem.add_dependency 'omniauth-oauth2', '~> 1.7.1'
+  gem.add_dependency 'omniauth', '~> 2.0'
+  gem.add_dependency 'omniauth-oauth2', '~> 1.7'
   gem.add_development_dependency 'rspec', '~> 3.1'
   gem.add_development_dependency 'rspec-its', '~> 1.0'
   gem.add_development_dependency 'simplecov'
