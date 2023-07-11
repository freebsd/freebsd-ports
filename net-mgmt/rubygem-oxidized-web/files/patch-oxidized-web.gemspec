--- oxidized-web.gemspec.orig	2023-07-09 18:50:01.343035000 +0100
+++ oxidized-web.gemspec	2023-07-09 23:15:10.104846000 +0100
@@ -25,12 +25,11 @@
   s.add_runtime_dependency(%q<haml>.freeze, ["~> 5.0"])
   s.add_runtime_dependency(%q<htmlentities>.freeze, ["~> 4.3"])
   s.add_runtime_dependency(%q<oxidized>.freeze, ["~> 0.26"])
-  s.add_runtime_dependency(%q<puma>.freeze, ["~> 3.11.4"])
+  s.add_runtime_dependency(%q<puma>.freeze, ["~> 6"])
   s.add_runtime_dependency(%q<sass>.freeze, ["~> 3.3"])
-  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 1.4", ">= 1.4.6"])
-  s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 1.4", ">= 1.4.6"])
+  s.add_runtime_dependency(%q<sinatra>.freeze, ["~> 3.0", ">= 3.0.6"])
+  s.add_runtime_dependency(%q<sinatra-contrib>.freeze, ["~> 3.0", ">= 3.0.6"])
   s.add_runtime_dependency(%q<json>.freeze, [">= 1.7.0"])
-  s.add_runtime_dependency(%q<rack-test>.freeze, ["~> 0.7.0"])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.0"])
   s.add_development_dependency(%q<rails_best_practices>.freeze, ["~> 1.19"])
   s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
