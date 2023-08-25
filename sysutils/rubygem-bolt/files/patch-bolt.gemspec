--- bolt.gemspec.orig	2023-08-25 18:06:17 UTC
+++ bolt.gemspec
@@ -40,7 +40,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
   s.add_runtime_dependency(%q<puppet-strings>.freeze, [">= 2.3.0", "< 5.0"])
   s.add_runtime_dependency(%q<r10k>.freeze, ["~> 3.10"])
-  s.add_runtime_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
+  s.add_runtime_dependency(%q<ruby_smb>.freeze, [">= 1.0", "< 4.0"])
   s.add_runtime_dependency(%q<terminal-table>.freeze, ["~> 3.0"])
   s.add_runtime_dependency(%q<winrm>.freeze, ["~> 2.0"])
   s.add_runtime_dependency(%q<winrm-fs>.freeze, ["~> 1.3"])
