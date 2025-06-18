--- gems/gitlab-backup-cli/gitlab-backup-cli.gemspec.orig	2025-06-18 04:18:20 UTC
+++ gems/gitlab-backup-cli/gitlab-backup-cli.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |spec|
   spec.add_dependency "activerecord", ">= 7"
   spec.add_dependency "activesupport", ">= 7"
   spec.add_dependency "bigdecimal", "~> 3.1"
-  spec.add_dependency "googleauth", "~> 1.8.1" # https://gitlab.com/gitlab-org/gitlab/-/issues/449019
+  spec.add_dependency "googleauth", "~> 1.8" # https://gitlab.com/gitlab-org/gitlab/-/issues/449019
   spec.add_dependency "google-cloud-storage_transfer", "~> 1.2.0"
   spec.add_dependency "mutex_m", "~> 0.3"
   spec.add_dependency "pg", "~> 1.5.6"
@@ -44,7 +44,7 @@ Gem::Specification.new do |spec|
   spec.add_dependency "json", "~> 2.7"
   spec.add_dependency "jwt", "~> 2.5"
   spec.add_dependency "logger", "~> 1.5"
-  spec.add_dependency "minitest", "~> 5.11.0"
+  spec.add_dependency "minitest", "~> 5.11"
   spec.add_dependency "parallel", "~> 1.19"
   spec.add_dependency "rack", "~> 2.2.9"
   spec.add_dependency "rexml", "~> 3.4.0"
