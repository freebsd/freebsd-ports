--- oxidized.gemspec.orig	2023-07-17 21:56:52.469385000 +0100
+++ oxidized.gemspec	2023-07-17 22:23:40.340439000 +0100
@@ -22,13 +22,13 @@
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<asetus>.freeze, ["~> 0.1"])
+  s.add_runtime_dependency(%q<asetus>.freeze, ["~> 0.4"])
   s.add_runtime_dependency(%q<bcrypt_pbkdf>.freeze, ["~> 1.0"])
   s.add_runtime_dependency(%q<ed25519>.freeze, ["~> 1.2"])
   s.add_runtime_dependency(%q<net-ssh>.freeze, ["~> 7.1"])
   s.add_runtime_dependency(%q<net-telnet>.freeze, ["~> 0.2"])
-  s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.6"])
-  s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.6"])
+  s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.5"])
+  s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.10"])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2"])
   s.add_development_dependency(%q<git>.freeze, ["~> 1"])
   s.add_development_dependency(%q<minitest>.freeze, ["~> 5.18"])
