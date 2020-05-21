--- oxidized.gemspec.orig	2020-05-10 08:29:19 UTC
+++ oxidized.gemspec
@@ -28,7 +28,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<ed25519>.freeze, ["~> 1.2"])
       s.add_runtime_dependency(%q<net-ssh>.freeze, ["~> 5"])
       s.add_runtime_dependency(%q<net-telnet>.freeze, ["~> 0.2"])
-      s.add_runtime_dependency(%q<rugged>.freeze, ["~> 0.28.0"])
+      s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.6"])
       s.add_development_dependency(%q<bundler>.freeze, ["~> 2.0"])
       s.add_development_dependency(%q<git>.freeze, ["~> 1"])
