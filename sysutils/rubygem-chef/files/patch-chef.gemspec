--- chef.gemspec.orig	2020-12-19 23:33:16 UTC
+++ chef.gemspec
@@ -28,7 +28,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<chef-utils>.freeze, ["= 15.14.0"])
       s.add_runtime_dependency(%q<train-core>.freeze, ["~> 3.2", ">= 3.2.28"])
       s.add_runtime_dependency(%q<train-winrm>.freeze, [">= 0.2.5"])
-      s.add_runtime_dependency(%q<license-acceptance>.freeze, ["~> 1.0", ">= 1.0.5"])
+      s.add_runtime_dependency(%q<license-acceptance>.freeze, ["~> 2.0", ">= 1.0.5"])
       s.add_runtime_dependency(%q<mixlib-cli>.freeze, [">= 2.1.1", "< 3.0"])
       s.add_runtime_dependency(%q<mixlib-log>.freeze, [">= 2.0.3", "< 4.0"])
       s.add_runtime_dependency(%q<mixlib-authentication>.freeze, [">= 2.1", "< 4"])
