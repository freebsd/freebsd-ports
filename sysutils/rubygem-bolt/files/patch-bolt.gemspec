--- bolt.gemspec.orig
+++ bolt.gemspec
@@ -26,7 +26,7 @@
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.5"])
       s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_runtime_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
       s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2"])
@@ -37,7 +37,7 @@
       s.add_runtime_dependency(%q<net-ssh-krb>.freeze, ["~> 0.5"])
       s.add_runtime_dependency(%q<orchestrator_client>.freeze, ["~> 0.4"])
       s.add_runtime_dependency(%q<puppet>.freeze, [">= 6.16.0", "< 7"])
-      s.add_runtime_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1.0"])
+      s.add_runtime_dependency(%q<puppetfile-resolver>.freeze, [">= 0.1.0"])
       s.add_runtime_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
       s.add_runtime_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
       s.add_runtime_dependency(%q<r10k>.freeze, ["~> 3.1"])
@@ -53,7 +53,7 @@
     else
       s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
       s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
       s.add_dependency(%q<jwt>.freeze, ["~> 2.2"])
@@ -64,7 +64,7 @@
       s.add_dependency(%q<net-ssh-krb>.freeze, ["~> 0.5"])
       s.add_dependency(%q<orchestrator_client>.freeze, ["~> 0.4"])
       s.add_dependency(%q<puppet>.freeze, [">= 6.16.0", "< 7"])
-      s.add_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1.0"])
+      s.add_dependency(%q<puppetfile-resolver>.freeze, [">= 0.1.0"])
       s.add_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
       s.add_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
       s.add_dependency(%q<r10k>.freeze, ["~> 3.1"])
@@ -81,7 +81,7 @@
   else
     s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
     s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-    s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+    s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
     s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
     s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
     s.add_dependency(%q<jwt>.freeze, ["~> 2.2"])
@@ -92,7 +92,7 @@
     s.add_dependency(%q<net-ssh-krb>.freeze, ["~> 0.5"])
     s.add_dependency(%q<orchestrator_client>.freeze, ["~> 0.4"])
     s.add_dependency(%q<puppet>.freeze, [">= 6.16.0", "< 7"])
-    s.add_dependency(%q<puppetfile-resolver>.freeze, ["~> 0.1.0"])
+    s.add_dependency(%q<puppetfile-resolver>.freeze, [">= 0.1.0"])
     s.add_dependency(%q<puppet-resource_api>.freeze, [">= 1.8.1"])
     s.add_dependency(%q<puppet-strings>.freeze, ["~> 2.3"])
     s.add_dependency(%q<r10k>.freeze, ["~> 3.1"])
