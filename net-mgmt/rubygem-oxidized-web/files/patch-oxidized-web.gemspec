--- oxidized-web.gemspec.orig	2024-03-03 09:20:49 UTC
+++ oxidized-web.gemspec
@@ -25,10 +25,10 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<haml>.freeze, ["~> 5.0".freeze])
   s.add_runtime_dependency(%q<htmlentities>.freeze, ["~> 4.3".freeze])
   s.add_runtime_dependency(%q<oxidized>.freeze, ["~> 0.26".freeze])
-  s.add_runtime_dependency(%q<puma>.freeze, ["~> 3.11.4".freeze])
+  s.add_runtime_dependency(%q<puma>.freeze, ["~> 6".freeze])
   s.add_runtime_dependency(%q<sass>.freeze, ["~> 3.3".freeze])
-  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4".freeze, ">= 1.4.6".freeze])
-  s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 1.4".freeze, ">= 1.4.6".freeze])
+  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 3.0".freeze, ">= 3.0.6".freeze])
+  s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 3.0".freeze, ">= 3.0.6".freeze])
   s.add_runtime_dependency(%q<json>.freeze, [">= 1.7.0".freeze])
   s.add_runtime_dependency(%q<rack-test>.freeze, ["~> 0.7.0".freeze])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.0".freeze])
