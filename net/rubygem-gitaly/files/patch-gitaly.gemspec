--- gitaly.gemspec.orig	2017-06-22 08:27:02 UTC
+++ gitaly.gemspec
@@ -21,8 +21,6 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<google-protobuf>.freeze, ["~> 3.1"])
-      s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.0"])
       s.add_development_dependency(%q<bundler>.freeze, ["~> 1.12"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
     else
