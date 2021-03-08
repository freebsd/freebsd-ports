--- grpc.gemspec.orig	2021-03-08 12:38:28.274882000 +0100
+++ grpc.gemspec	2021-03-08 12:38:46.022872000 +0100
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<google-protobuf>.freeze, ["~> 3.12"])
+      s.add_runtime_dependency(%q<google-protobuf>.freeze, ["~> 3.14.0"])
       s.add_runtime_dependency(%q<googleapis-common-protos-types>.freeze, ["~> 1.0"])
       s.add_development_dependency(%q<bundler>.freeze, [">= 1.9"])
       s.add_development_dependency(%q<facter>.freeze, ["~> 2.4"])
