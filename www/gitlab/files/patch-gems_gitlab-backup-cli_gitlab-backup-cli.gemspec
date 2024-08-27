--- gems/gitlab-backup-cli/gitlab-backup-cli.gemspec.orig	2024-08-27 06:12:18 UTC
+++ gems/gitlab-backup-cli/gitlab-backup-cli.gemspec
@@ -25,7 +25,7 @@ Gem::Specification.new do |spec|
   spec.require_paths = ["lib"]
 
   spec.add_dependency "activesupport", "< 7.2"
-  spec.add_dependency "googleauth", "~> 1.8.1" # https://gitlab.com/gitlab-org/gitlab/-/issues/449019
+  spec.add_dependency "googleauth", "~> 1.8" # https://gitlab.com/gitlab-org/gitlab/-/issues/449019
   spec.add_dependency "google-cloud-storage_transfer", "~> 1.2.0"
   spec.add_dependency "rainbow", "~> 3.0"
   spec.add_dependency "thor", "~> 1.3"
