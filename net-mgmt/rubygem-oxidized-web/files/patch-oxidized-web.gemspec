--- oxidized-web.gemspec.orig	2025-12-10 20:00:58 UTC
+++ oxidized-web.gemspec
@@ -23,10 +23,10 @@ Gem::Specification.new do |s|
 
   s.add_runtime_dependency(%q<charlock_holmes>.freeze, [">= 0.7.5".freeze, "< 0.8.0".freeze])
   s.add_runtime_dependency(%q<emk-sinatra-url-for>.freeze, ["~> 0.2".freeze])
-  s.add_runtime_dependency(%q<haml>.freeze, [">= 6.0.0".freeze, "< 7.0.0".freeze])
-  s.add_runtime_dependency(%q<htmlentities>.freeze, [">= 4.3.0".freeze, "< 4.5.0".freeze])
-  s.add_runtime_dependency(%q<json>.freeze, [">= 2.3.0".freeze, "< 2.17.0".freeze])
-  s.add_runtime_dependency(%q<oxidized>.freeze, [">= 0.34.1".freeze])
+  s.add_runtime_dependency(%q<haml>.freeze, [">= 7.0.1".freeze, "~> 7.0".freeze])
+  s.add_runtime_dependency(%q<htmlentities>.freeze, [">= 4.3.0".freeze, "< 5.0.0".freeze])
+  s.add_runtime_dependency(%q<json>.freeze, [">= 2.3.0".freeze, "< 3.0.0".freeze])
+  s.add_runtime_dependency(%q<oxidized>.freeze, ["~> 0.35.0".freeze])
   s.add_runtime_dependency(%q<puma>.freeze, [">= 6.6".freeze, "< 7.2".freeze])
   s.add_runtime_dependency(%q<sinatra>.freeze, [">= 4.1.1".freeze, "< 4.3.0".freeze])
   s.add_runtime_dependency(%q<sinatra-contrib>.freeze, [">= 4.1.1".freeze, "< 4.3.0".freeze])
