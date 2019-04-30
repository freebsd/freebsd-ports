--- bolt.gemspec.orig	2019-03-08 16:12:11 UTC
+++ bolt.gemspec
@@ -24,8 +24,8 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.5"])
-      s.add_runtime_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_runtime_dependency(%q<addressable>.freeze, [">= 2.5"])
+      s.add_runtime_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_runtime_dependency(%q<docker-api>.freeze, ["~> 1.34"])
       s.add_runtime_dependency(%q<logging>.freeze, ["~> 2.2"])
@@ -45,8 +45,8 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
       s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0"])
     else
-      s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
-      s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+      s.add_dependency(%q<addressable>.freeze, [">= 2.5"])
+      s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
       s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
       s.add_dependency(%q<docker-api>.freeze, ["~> 1.34"])
       s.add_dependency(%q<logging>.freeze, ["~> 2.2"])
@@ -67,8 +67,8 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<rspec>.freeze, ["~> 3.0"])
     end
   else
-    s.add_dependency(%q<addressable>.freeze, ["~> 2.5"])
-    s.add_dependency(%q<CFPropertyList>.freeze, ["~> 2.2"])
+    s.add_dependency(%q<addressable>.freeze, [">= 2.5"])
+    s.add_dependency(%q<CFPropertyList>.freeze, [">= 2.2"])
     s.add_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0"])
     s.add_dependency(%q<docker-api>.freeze, ["~> 1.34"])
     s.add_dependency(%q<logging>.freeze, ["~> 2.2"])
