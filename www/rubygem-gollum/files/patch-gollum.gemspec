--- gollum.gemspec.orig	2024-08-15 16:05:42 UTC
+++ gollum.gemspec
@@ -38,7 +38,6 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<sprockets>.freeze, ["~> 4.1".freeze])
   s.add_runtime_dependency(%q<sprockets-helpers>.freeze, ["~> 1.2".freeze])
   s.add_runtime_dependency(%q<rss>.freeze, ["~> 0.3".freeze])
-  s.add_runtime_dependency(%q<therubyrhino>.freeze, ["~> 2.1.0".freeze])
   s.add_runtime_dependency(%q<webrick>.freeze, ["~> 1.7".freeze])
   s.add_runtime_dependency(%q<i18n>.freeze, ["~> 1.8".freeze])
   s.add_development_dependency(%q<rack-test>.freeze, ["~> 0.6.3".freeze])
