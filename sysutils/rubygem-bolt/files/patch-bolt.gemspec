--- bolt.gemspec.orig
+++ bolt.gemspec
@@ -25,8 +25,8 @@
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.5"])
-      s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_runtime_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_runtime_dependency(%q<aws-sdk-ec2>.freeze, [">= 1"])
+      s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<docker-api>.freeze, ["~> 1.34"])
       s.add_runtime_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
@@ -48,8 +48,8 @@
       s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0"])
     else
       s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
-      s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-      s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_dependency(%q<aws-sdk-ec2>.freeze, [">= 1"])
+      s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_dependency(%q<docker-api>.freeze, ["~> 1.34"])
       s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
@@ -72,8 +72,8 @@
     end
   else
     s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
-    s.add_dependency(%q<aws-sdk-ec2>.freeze, ["~> 1"])
-    s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+    s.add_dependency(%q<aws-sdk-ec2>.freeze, [">= 1"])
+    s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
     s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
     s.add_dependency(%q<docker-api>.freeze, ["~> 1.34"])
     s.add_dependency(%q<hiera-eyaml>.freeze, ["~> 3"])
