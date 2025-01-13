--- oxidized-web.gemspec.orig	2025-01-13 18:59:26 UTC
+++ oxidized-web.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<htmlentities>.freeze, ["~> 4.3".freeze])
   s.add_runtime_dependency(%q<json>.freeze, ["~> 2.3".freeze])
   s.add_runtime_dependency(%q<oxidized>.freeze, ["~> 0.26".freeze])
-  s.add_runtime_dependency(%q<puma>.freeze, [">= 3.11.4".freeze, "< 6.5.0".freeze])
+  s.add_runtime_dependency(%q<puma>.freeze, [">= 3.11.4".freeze, "< 7.0".freeze])
   s.add_runtime_dependency(%q<sinatra>.freeze, [">= 1.4.6".freeze, "< 5.0".freeze])
   s.add_runtime_dependency(%q<sinatra-contrib>.freeze, [">= 1.4.6".freeze, "< 5.0".freeze])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2".freeze])
