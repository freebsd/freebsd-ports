--- r10k.gemspec.orig
+++ r10k.gemspec
@@ -24,7 +24,7 @@
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<colored>.freeze, ["= 1.2"])
-      s.add_runtime_dependency(%q<cri>.freeze, ["= 2.15.6"])
+      s.add_runtime_dependency(%q<cri>.freeze, ["~> 2.15.6"])
       s.add_runtime_dependency(%q<log4r>.freeze, ["= 1.1.10"])
       s.add_runtime_dependency(%q<multi_json>.freeze, ["~> 1.10"])
       s.add_runtime_dependency(%q<puppet_forge>.freeze, ["~> 2.2.8"])
@@ -35,7 +35,7 @@
       s.add_development_dependency(%q<minitar>.freeze, ["~> 0.6.1"])
     else
       s.add_dependency(%q<colored>.freeze, ["= 1.2"])
-      s.add_dependency(%q<cri>.freeze, ["= 2.15.6"])
+      s.add_dependency(%q<cri>.freeze, ["~> 2.15.6"])
       s.add_dependency(%q<log4r>.freeze, ["= 1.1.10"])
       s.add_dependency(%q<multi_json>.freeze, ["~> 1.10"])
       s.add_dependency(%q<puppet_forge>.freeze, ["~> 2.2.8"])
@@ -47,7 +47,7 @@
     end
   else
     s.add_dependency(%q<colored>.freeze, ["= 1.2"])
-    s.add_dependency(%q<cri>.freeze, ["= 2.15.6"])
+    s.add_dependency(%q<cri>.freeze, ["~> 2.15.6"])
     s.add_dependency(%q<log4r>.freeze, ["= 1.1.10"])
     s.add_dependency(%q<multi_json>.freeze, ["~> 1.10"])
     s.add_dependency(%q<puppet_forge>.freeze, ["~> 2.2.8"])
