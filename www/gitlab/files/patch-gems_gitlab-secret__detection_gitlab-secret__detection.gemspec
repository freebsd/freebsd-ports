--- gems/gitlab-secret_detection/gitlab-secret_detection.gemspec.orig	2024-12-18 07:22:32 UTC
+++ gems/gitlab-secret_detection/gitlab-secret_detection.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |spec|
   spec.files = Dir['lib/**/*.rb']
   spec.require_paths = ["lib"]
 
-  spec.add_runtime_dependency "grpc", "= 1.63.0"
+  spec.add_runtime_dependency "grpc", "~> 1.63"
   spec.add_runtime_dependency "grpc-tools", "= 1.63.0"
   spec.add_runtime_dependency "parallel", "~> 1.22"
   spec.add_runtime_dependency "re2", "~> 2.4"
