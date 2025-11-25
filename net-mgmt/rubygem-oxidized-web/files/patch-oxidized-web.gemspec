--- oxidized-web.gemspec.orig	2025-11-11 21:42:23.300288000 +0000
+++ oxidized-web.gemspec	2025-11-11 21:46:40.770850000 +0000
@@ -23,13 +23,13 @@

   s.add_runtime_dependency(%q<charlock_holmes>.freeze, [">= 0.7.5".freeze, "< 0.8.0".freeze])
   s.add_runtime_dependency(%q<emk-sinatra-url-for>.freeze, ["~> 0.2".freeze])
-  s.add_runtime_dependency(%q<haml>.freeze, [">= 6.0.0".freeze, "< 6.4.0".freeze])
+  s.add_runtime_dependency(%q<haml>.freeze, [">= 7.0.1".freeze, "~> 7.0".freeze])
   s.add_runtime_dependency(%q<htmlentities>.freeze, [">= 4.3.0".freeze, "< 4.4.0".freeze])
-  s.add_runtime_dependency(%q<json>.freeze, [">= 2.3.0".freeze, "< 2.14.0".freeze])
+  s.add_runtime_dependency(%q<json>.freeze, [">= 2.3.0".freeze, "~> 2.3".freeze])
   s.add_runtime_dependency(%q<oxidized>.freeze, ["~> 0.34.1".freeze])
   s.add_runtime_dependency(%q<puma>.freeze, ["~> 6.6.0".freeze])
-  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 4.1.1".freeze])
-  s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 4.1.1".freeze])
+  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 4.1".freeze])
+  s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 4.1".freeze])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2".freeze])
   s.add_development_dependency(%q<minitest>.freeze, ["~> 5.18".freeze])
   s.add_development_dependency(%q<mocha>.freeze, ["~> 2.1".freeze])
