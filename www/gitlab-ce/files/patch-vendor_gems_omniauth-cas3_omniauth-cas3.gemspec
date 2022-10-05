--- vendor/gems/omniauth-cas3/omniauth-cas3.gemspec.orig	2022-10-04 14:28:17 UTC
+++ vendor/gems/omniauth-cas3/omniauth-cas3.gemspec
@@ -14,7 +14,7 @@ Gem::Specification.new do |gem|
   gem.require_paths = ["lib"]
   gem.version       = Omniauth::Cas3::VERSION
 
-  gem.add_dependency 'omniauth',                '~> 1.2', '< 3'
+  gem.add_dependency 'omniauth',                '>= 1.2', '< 3'
   gem.add_dependency 'nokogiri',                '~> 1.7', '>= 1.7.1'
   gem.add_dependency 'addressable',             '~> 2.3'
 
