--- oxidized.gemspec.orig	2024-02-27 18:04:00 UTC
+++ oxidized.gemspec
@@ -22,13 +22,13 @@ Gem::Specification.new do |s|
 
   s.specification_version = 4
 
-  s.add_runtime_dependency(%q<asetus>.freeze, ["~> 0.1".freeze])
+  s.add_runtime_dependency(%q<asetus>.freeze, ["~> 0.4".freeze])
   s.add_runtime_dependency(%q<bcrypt_pbkdf>.freeze, ["~> 1.0".freeze])
   s.add_runtime_dependency(%q<ed25519>.freeze, ["~> 1.2".freeze])
   s.add_runtime_dependency(%q<net-ssh>.freeze, ["~> 7.1".freeze])
   s.add_runtime_dependency(%q<net-telnet>.freeze, ["~> 0.2".freeze])
-  s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.6".freeze])
-  s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.6".freeze])
+  s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.5".freeze])
+  s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.10".freeze])
   s.add_development_dependency(%q<bundler>.freeze, ["~> 2.2".freeze])
   s.add_development_dependency(%q<git>.freeze, ["~> 1".freeze])
   s.add_development_dependency(%q<minitest>.freeze, ["~> 5.18".freeze])
