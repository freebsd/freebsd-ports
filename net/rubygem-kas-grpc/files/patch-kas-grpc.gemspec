--- kas-grpc.gemspec.orig	2021-11-22 11:08:46 UTC
+++ kas-grpc.gemspec
@@ -20,12 +20,12 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.0"])
+      s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
     else
-      s.add_dependency(%q<grpc>.freeze, ["~> 1.0"])
+      s.add_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
     end
   else
-    s.add_dependency(%q<grpc>.freeze, ["~> 1.0"])
+    s.add_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
   end
 end
 
