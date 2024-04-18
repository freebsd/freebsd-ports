--- vagrant.gemspec.orig	2023-06-15 20:40:35 UTC
+++ vagrant.gemspec
@@ -16,7 +16,7 @@ Gem::Specification.new do |s|
   s.required_rubygems_version = ">= 1.3.6"
 
   s.add_dependency "bcrypt_pbkdf", "~> 1.1"
-  s.add_dependency "childprocess", "~> 4.1.0"
+  s.add_dependency "childprocess", "~> 5.0.0"
   s.add_dependency "ed25519", "~> 1.3.0"
   s.add_dependency "erubi"
   s.add_dependency 'googleapis-common-protos-types', '~> 1.3'
@@ -34,7 +34,7 @@ Gem::Specification.new do |s|
   s.add_dependency "rexml", "~> 3.2"
   s.add_dependency "rgl", "~> 0.5.10"
   s.add_dependency "rubyzip", "~> 2.3.2"
-  s.add_dependency "vagrant_cloud", "~> 3.0.5"
+  s.add_dependency "vagrant_cloud", "~> 3.1.1"
   s.add_dependency "wdm", "~> 0.1.1"
   s.add_dependency "winrm", ">= 2.3.6", "< 3.0"
   s.add_dependency "winrm-elevated", ">= 1.2.3", "< 2.0"
