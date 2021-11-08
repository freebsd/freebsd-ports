--- bolt.gemspec.orig	2021-11-08 22:39:08 UTC
+++ bolt.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.5"])
       s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_runtime_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.9.25", "< 2.0.0"])
       s.add_runtime_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
@@ -42,7 +42,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
       s.add_runtime_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
       s.add_runtime_dependency(%q<r10k>.freeze, ["~> 3.10"])
-      s.add_runtime_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
+      s.add_runtime_dependency(%q<ruby_smb>.freeze, [">= 1.0"])
       s.add_runtime_dependency(%q<terminal-table>.freeze, ["~> 3.0"])
       s.add_runtime_dependency(%q<winrm>.freeze, ["~> 2.0"])
       s.add_runtime_dependency(%q<winrm-fs>.freeze, ["~> 1.3"])
@@ -54,7 +54,7 @@ Gem::Specification.new do |s|
     else
       s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
       s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_dependency(%q<ffi>.freeze, [">= 1.9.25", "< 2.0.0"])
       s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
@@ -70,7 +70,7 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
       s.add_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
       s.add_dependency(%q<r10k>.freeze, ["~> 3.10"])
-      s.add_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
+      s.add_dependency(%q<ruby_smb>.freeze, [">= 1.0"])
       s.add_dependency(%q<terminal-table>.freeze, ["~> 3.0"])
       s.add_dependency(%q<winrm>.freeze, ["~> 2.0"])
       s.add_dependency(%q<winrm-fs>.freeze, ["~> 1.3"])
@@ -83,7 +83,7 @@ Gem::Specification.new do |s|
   else
     s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
     s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-    s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+    s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
     s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
     s.add_dependency(%q<ffi>.freeze, [">= 1.9.25", "< 2.0.0"])
     s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
@@ -99,7 +99,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
     s.add_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
     s.add_dependency(%q<r10k>.freeze, ["~> 3.10"])
-    s.add_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
+    s.add_dependency(%q<ruby_smb>.freeze, [">= 1.0"])
     s.add_dependency(%q<terminal-table>.freeze, ["~> 3.0"])
     s.add_dependency(%q<winrm>.freeze, ["~> 2.0"])
     s.add_dependency(%q<winrm-fs>.freeze, ["~> 1.3"])
