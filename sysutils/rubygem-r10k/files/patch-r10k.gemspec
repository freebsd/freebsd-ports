--- r10k.gemspec.orig	2021-08-18 18:36:32 UTC
+++ r10k.gemspec
@@ -24,13 +24,13 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<colored2>.freeze, ["= 3.1.2"])
-      s.add_runtime_dependency(%q<cri>.freeze, ["= 2.15.10"])
+      s.add_runtime_dependency(%q<cri>.freeze, [">= 2.15.10"])
       s.add_runtime_dependency(%q<log4r>.freeze, ["= 1.1.10"])
       s.add_runtime_dependency(%q<multi_json>.freeze, ["~> 1.10"])
       s.add_runtime_dependency(%q<puppet_forge>.freeze, ["~> 2.3.0"])
       s.add_runtime_dependency(%q<gettext-setup>.freeze, ["~> 0.24"])
-      s.add_runtime_dependency(%q<fast_gettext>.freeze, ["~> 1.1.0"])
-      s.add_runtime_dependency(%q<gettext>.freeze, [">= 3.0.2", "< 3.3.0"])
+      s.add_runtime_dependency(%q<fast_gettext>.freeze, [">= 1.1.0"])
+      s.add_runtime_dependency(%q<gettext>.freeze, [">= 3.0.2"])
       s.add_runtime_dependency(%q<jwt>.freeze, ["~> 2.2.3"])
       s.add_development_dependency(%q<rspec>.freeze, ["~> 3.1"])
       s.add_development_dependency(%q<rake>.freeze, [">= 0"])
@@ -38,13 +38,13 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<minitar>.freeze, ["~> 0.9.0"])
     else
       s.add_dependency(%q<colored2>.freeze, ["= 3.1.2"])
-      s.add_dependency(%q<cri>.freeze, ["= 2.15.10"])
+      s.add_dependency(%q<cri>.freeze, [">= 2.15.10"])
       s.add_dependency(%q<log4r>.freeze, ["= 1.1.10"])
       s.add_dependency(%q<multi_json>.freeze, ["~> 1.10"])
       s.add_dependency(%q<puppet_forge>.freeze, ["~> 2.3.0"])
       s.add_dependency(%q<gettext-setup>.freeze, ["~> 0.24"])
-      s.add_dependency(%q<fast_gettext>.freeze, ["~> 1.1.0"])
-      s.add_dependency(%q<gettext>.freeze, [">= 3.0.2", "< 3.3.0"])
+      s.add_dependency(%q<fast_gettext>.freeze, [">= 1.1.0"])
+      s.add_dependency(%q<gettext>.freeze, [">= 3.0.2"])
       s.add_dependency(%q<jwt>.freeze, ["~> 2.2.3"])
       s.add_dependency(%q<rspec>.freeze, ["~> 3.1"])
       s.add_dependency(%q<rake>.freeze, [">= 0"])
@@ -53,13 +53,13 @@ Gem::Specification.new do |s|
     end
   else
     s.add_dependency(%q<colored2>.freeze, ["= 3.1.2"])
-    s.add_dependency(%q<cri>.freeze, ["= 2.15.10"])
+    s.add_dependency(%q<cri>.freeze, [">= 2.15.10"])
     s.add_dependency(%q<log4r>.freeze, ["= 1.1.10"])
     s.add_dependency(%q<multi_json>.freeze, ["~> 1.10"])
     s.add_dependency(%q<puppet_forge>.freeze, ["~> 2.3.0"])
     s.add_dependency(%q<gettext-setup>.freeze, ["~> 0.24"])
-    s.add_dependency(%q<fast_gettext>.freeze, ["~> 1.1.0"])
-    s.add_dependency(%q<gettext>.freeze, [">= 3.0.2", "< 3.3.0"])
+    s.add_dependency(%q<fast_gettext>.freeze, [">= 1.1.0"])
+    s.add_dependency(%q<gettext>.freeze, [">= 3.0.2"])
     s.add_dependency(%q<jwt>.freeze, ["~> 2.2.3"])
     s.add_dependency(%q<rspec>.freeze, ["~> 3.1"])
     s.add_dependency(%q<rake>.freeze, [">= 0"])
