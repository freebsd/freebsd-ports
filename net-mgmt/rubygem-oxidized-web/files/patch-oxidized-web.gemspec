--- oxidized-web.gemspec.orig	2023-02-05 19:04:08 UTC
+++ oxidized-web.gemspec
@@ -25,12 +25,12 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<haml>.freeze, ["~> 5.0"])
   s.add_runtime_dependency(%q<htmlentities>.freeze, ["~> 4.3"])
   s.add_runtime_dependency(%q<oxidized>.freeze, ["~> 0.26"])
-  s.add_runtime_dependency(%q<puma>.freeze, ["~> 3.11.4"])
+  s.add_runtime_dependency(%q<puma>.freeze, ["~> 5.6"])
   s.add_runtime_dependency(%q<sass>.freeze, ["~> 3.3"])
   s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4", ">= 1.4.6"])
   s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 1.4", ">= 1.4.6"])
   s.add_runtime_dependency(%q<json>.freeze, [">= 1.7.0"])
-  s.add_runtime_dependency(%q<rack-test>.freeze, ["~> 0.7.0"])
+  s.add_runtime_dependency(%q<rack-test>.freeze, [">= 0.7.0"])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.0"])
   s.add_development_dependency(%q<rails_best_practices>.freeze, ["~> 1.19"])
   s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
