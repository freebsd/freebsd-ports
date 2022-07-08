--- bolt.gemspec.orig	2022-07-08 20:20:58 UTC
+++ bolt.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
   if s.respond_to? :add_runtime_dependency then
     s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.5"])
     s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-    s.add_runtime_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+    s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
     s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
     s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.9.25", "< 2.0.0"])
     s.add_runtime_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
@@ -35,7 +35,7 @@ Gem::Specification.new do |s|
     s.add_runtime_dependency(%q<logging>.freeze, ["~> 2.2"])
     s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.6"])
     s.add_runtime_dependency(%q<net-scp>.freeze, ["~> 1.2"])
-    s.add_runtime_dependency(%q<net-ssh>.freeze, [">= 4.0", "< 7.0"])
+    s.add_runtime_dependency(%q<net-ssh>.freeze, [">= 4.0"])
     s.add_runtime_dependency(%q<net-ssh-krb>.freeze, ["~> 0.5"])
     s.add_runtime_dependency(%q<orchestrator_client>.freeze, ["~> 0.5"])
     s.add_runtime_dependency(%q<puppet>.freeze, [">= 6.18.0"])
@@ -43,7 +43,7 @@ Gem::Specification.new do |s|
     s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
     s.add_runtime_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
     s.add_runtime_dependency(%q<r10k>.freeze, ["~> 3.10"])
-    s.add_runtime_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
+    s.add_runtime_dependency(%q<ruby_smb>.freeze, [">= 1.0"])
     s.add_runtime_dependency(%q<terminal-table>.freeze, ["~> 3.0"])
     s.add_runtime_dependency(%q<winrm>.freeze, ["~> 2.0"])
     s.add_runtime_dependency(%q<winrm-fs>.freeze, ["~> 1.3"])
@@ -63,7 +63,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<logging>.freeze, ["~> 2.2"])
     s.add_dependency(%q<minitar>.freeze, ["~> 0.6"])
     s.add_dependency(%q<net-scp>.freeze, ["~> 1.2"])
-    s.add_dependency(%q<net-ssh>.freeze, [">= 4.0", "< 7.0"])
+    s.add_dependency(%q<net-ssh>.freeze, [">= 4.0"])
     s.add_dependency(%q<net-ssh-krb>.freeze, ["~> 0.5"])
     s.add_dependency(%q<orchestrator_client>.freeze, ["~> 0.5"])
     s.add_dependency(%q<puppet>.freeze, [">= 6.18.0"])
