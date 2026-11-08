--- gollum.gemspec.orig	2026-09-23 07:45:17 UTC
+++ gollum.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<rdoc>.freeze, ["~> 6".freeze])
+  s.add_runtime_dependency(%q<rdoc>.freeze, ["~> 8".freeze])
   s.add_runtime_dependency(%q<gollum-lib>.freeze, ["~> 6.0".freeze])
   s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 2.3".freeze])
   s.add_runtime_dependency(%q<kramdown-parser-gfm>.freeze, ["~> 1.1.0".freeze])
@@ -38,7 +38,6 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<sprockets>.freeze, ["~> 4.1".freeze])
   s.add_runtime_dependency(%q<sprockets-helpers>.freeze, ["~> 1.2".freeze])
   s.add_runtime_dependency(%q<rss>.freeze, ["~> 0.3".freeze])
-  s.add_runtime_dependency(%q<therubyrhino>.freeze, ["~> 2.1.0".freeze])
   s.add_runtime_dependency(%q<webrick>.freeze, ["~> 1.7".freeze])
   s.add_runtime_dependency(%q<i18n>.freeze, ["~> 1.8".freeze])
   s.add_development_dependency(%q<rack-test>.freeze, ["~> 0.6.3".freeze])
