--- bolt.gemspec.orig	2020-04-28 03:06:17 UTC
+++ bolt.gemspec
@@ -25,8 +25,8 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.5"])
-      s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_runtime_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, [">= 1"])
+      s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
       s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2"])
@@ -39,7 +39,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<puppet>.freeze, [">= 6.11.0", "< 7"])
       s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
       s.add_runtime_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
-      s.add_runtime_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1.0"])
+      s.add_runtime_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1"])
       s.add_runtime_dependency(%q<r10k>.freeze, ["~> 3.1"])
       s.add_runtime_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<terminal-table>.freeze, ["~> 1.8"])
@@ -52,8 +52,8 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0"])
     else
       s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
-      s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_dependency(%q<aws-sdk-ec2>.freeze, [">= 1"])
+      s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
       s.add_dependency(%q<jwt>.freeze, ["~> 2.2"])
@@ -66,7 +66,7 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<puppet>.freeze, [">= 6.11.0", "< 7"])
       s.add_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
       s.add_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
-      s.add_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1.0"])
+      s.add_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1"])
       s.add_dependency(%q<r10k>.freeze, ["~> 3.1"])
       s.add_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
       s.add_dependency(%q<terminal-table>.freeze, ["~> 1.8"])
@@ -80,8 +80,8 @@ Gem::Specification.new do |s|
     end
   else
     s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
-    s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-    s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+    s.add_dependency(%q<aws-sdk-ec2>.freeze, [">= 1"])
+    s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
     s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
     s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
     s.add_dependency(%q<jwt>.freeze, ["~> 2.2"])
@@ -94,7 +94,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<puppet>.freeze, [">= 6.11.0", "< 7"])
     s.add_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
     s.add_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
-    s.add_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1.0"])
+    s.add_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1"])
     s.add_dependency(%q<r10k>.freeze, ["~> 3.1"])
     s.add_dependency(%q<ruby_smb>.freeze, ["~> 1.0"])
     s.add_dependency(%q<terminal-table>.freeze, ["~> 1.8"])
