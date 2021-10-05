--- activestorage.gemspec.orig	2021-10-05 06:22:11 UTC
+++ activestorage.gemspec
@@ -28,14 +28,14 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<activejob>.freeze, ["= 6.1.3.2"])
       s.add_runtime_dependency(%q<activerecord>.freeze, ["= 6.1.3.2"])
       s.add_runtime_dependency(%q<marcel>.freeze, ["~> 1.0.0"])
-      s.add_runtime_dependency(%q<mini_mime>.freeze, ["~> 1.0.2"])
+      s.add_runtime_dependency(%q<mini_mime>.freeze, ["~> 1.0"])
     else
       s.add_dependency(%q<activesupport>.freeze, ["= 6.1.3.2"])
       s.add_dependency(%q<actionpack>.freeze, ["= 6.1.3.2"])
       s.add_dependency(%q<activejob>.freeze, ["= 6.1.3.2"])
       s.add_dependency(%q<activerecord>.freeze, ["= 6.1.3.2"])
       s.add_dependency(%q<marcel>.freeze, ["~> 1.0.0"])
-      s.add_dependency(%q<mini_mime>.freeze, ["~> 1.0.2"])
+      s.add_dependency(%q<mini_mime>.freeze, ["~> 1.0"])
     end
   else
     s.add_dependency(%q<activesupport>.freeze, ["= 6.1.3.2"])
@@ -43,7 +43,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<activejob>.freeze, ["= 6.1.3.2"])
     s.add_dependency(%q<activerecord>.freeze, ["= 6.1.3.2"])
     s.add_dependency(%q<marcel>.freeze, ["~> 1.0.0"])
-    s.add_dependency(%q<mini_mime>.freeze, ["~> 1.0.2"])
+    s.add_dependency(%q<mini_mime>.freeze, ["~> 1.0"])
   end
 end
 
