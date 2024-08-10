--- bolt.gemspec.orig	2024-08-09 15:24:36 UTC
+++ bolt.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2".freeze])
   s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0".freeze])
   s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.9.25".freeze, "< 2.0.0".freeze])
-  s.add_runtime_dependency(%q<hiera-eyaml>.freeze, ["~> 3".freeze])
+  s.add_runtime_dependency(%q<hiera-eyaml>.freeze, [">= 3".freeze])
   s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2".freeze])
   s.add_runtime_dependency(%q<logging>.freeze, ["~> 2.2".freeze])
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.6".freeze])
@@ -39,8 +39,8 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<puppetfile-resolver>.freeze, [">= 0.6.2".freeze, "< 1.0".freeze])
   s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1".freeze])
   s.add_runtime_dependency(%q<puppet-strings>.freeze, [">= 2.3.0".freeze, "< 5.0".freeze])
-  s.add_runtime_dependency(%q<r10k>.freeze, ["~> 3.10".freeze])
-  s.add_runtime_dependency(%q<ruby_smb>.freeze, ["~> 1.0".freeze])
+  s.add_runtime_dependency(%q<r10k>.freeze, [">= 3.10".freeze, "< 5.0".freeze])
+  s.add_runtime_dependency(%q<ruby_smb>.freeze, [">= 1.0".freeze, "< 4.0".freeze])
   s.add_runtime_dependency(%q<terminal-table>.freeze, ["~> 3.0".freeze])
   s.add_runtime_dependency(%q<winrm>.freeze, ["~> 2.0".freeze])
   s.add_runtime_dependency(%q<winrm-fs>.freeze, ["~> 1.3".freeze])
