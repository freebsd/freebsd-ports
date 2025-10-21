--- openbolt.gemspec.orig	2025-10-21 18:36:14 UTC
+++ openbolt.gemspec
@@ -39,7 +39,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<puppetfile-resolver>.freeze, [">= 0.6.2".freeze, "< 1.0".freeze])
   s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1".freeze])
   s.add_runtime_dependency(%q<r10k>.freeze, [">= 3.10".freeze, "< 6".freeze])
-  s.add_runtime_dependency(%q<ruby_smb>.freeze, ["~> 1.0".freeze])
+  s.add_runtime_dependency(%q<ruby_smb>.freeze, [">= 1.0".freeze])
   s.add_runtime_dependency(%q<terminal-table>.freeze, ["~> 3.0".freeze])
   s.add_runtime_dependency(%q<winrm>.freeze, ["~> 2.0".freeze])
   s.add_runtime_dependency(%q<winrm-fs>.freeze, ["~> 1.3".freeze])
