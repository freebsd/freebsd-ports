--- vendor/gems/sidekiq/sidekiq.gemspec.orig	2025-11-03 12:17:46 UTC
+++ vendor/gems/sidekiq/sidekiq.gemspec
@@ -8,7 +8,7 @@ Gem::Specification.new do |gem|
   gem.homepage = "https://sidekiq.org"
   gem.license = "LGPL-3.0"
 
-  gem.executables = ["sidekiq", "sidekiqmon"]
+  #gem.executables = ["sidekiq", "sidekiqmon"]
   gem.files = %w[
     sidekiq.gemspec
     README.md
