Obtained from:	https://github.com/rails/rails/commit/b80a2bdeb955c81649e483f2f020a3d5f407c2f9

--- activestorage.gemspec.orig	2021-05-06 14:05:12 UTC
+++ activestorage.gemspec
@@ -28,7 +28,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<activejob>.freeze, ["= 6.1.3.2"])
       s.add_runtime_dependency(%q<activerecord>.freeze, ["= 6.1.3.2"])
       s.add_runtime_dependency(%q<marcel>.freeze, ["~> 1.0.0"])
-      s.add_runtime_dependency(%q<mini_mime>.freeze, ["~> 1.0.2"])
+      s.add_runtime_dependency(%q<mini_mime>.freeze, [">= 1.1.0"])
     else
       s.add_dependency(%q<activesupport>.freeze, ["= 6.1.3.2"])
       s.add_dependency(%q<actionpack>.freeze, ["= 6.1.3.2"])
