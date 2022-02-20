--- spamcheck.gemspec.orig	2022-01-27 10:31:07 UTC
+++ spamcheck.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
   end
 
   if s.respond_to? :add_runtime_dependency then
-    s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.0"])
+    s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
   else
     s.add_dependency(%q<grpc>.freeze, ["~> 1.0"])
   end
