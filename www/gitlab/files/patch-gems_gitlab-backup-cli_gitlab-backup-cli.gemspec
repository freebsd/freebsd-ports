--- gems/gitlab-backup-cli/gitlab-backup-cli.gemspec.orig	2025-02-19 06:08:46 UTC
+++ gems/gitlab-backup-cli/gitlab-backup-cli.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |spec|
 
   spec.add_dependency "activerecord", ">= 7"
   spec.add_dependency "activesupport", ">= 7"
-  spec.add_dependency "googleauth", "~> 1.8.1" # https://gitlab.com/gitlab-org/gitlab/-/issues/449019
+  spec.add_dependency "googleauth", "~> 1.8" # https://gitlab.com/gitlab-org/gitlab/-/issues/449019
   spec.add_dependency "google-cloud-storage_transfer", "~> 1.2.0"
   spec.add_dependency "pg", "~> 1.5.6"
   spec.add_dependency "rainbow", "~> 3.0"
@@ -38,11 +38,11 @@ Gem::Specification.new do |spec|
   spec.add_dependency "concurrent-ruby", "~> 1.1"
   spec.add_dependency "faraday", "~> 2"
   spec.add_dependency "google-protobuf", "~> 3.25", ">= 3.25.3"
-  spec.add_dependency "grpc", "= 1.63.0"
+  spec.add_dependency "grpc", "~> 1.63"
   spec.add_dependency "json", "~> 2.7.2"
   spec.add_dependency "jwt", "~> 2.5"
   spec.add_dependency "logger", "~> 1.5.3"
-  spec.add_dependency "minitest", "~> 5.11.0"
+  spec.add_dependency "minitest", "~> 5.11"
   spec.add_dependency "parallel", "~> 1.19"
   spec.add_dependency "rack", "~> 2.2.9"
   spec.add_dependency "rexml", "~> 3.4.0"
