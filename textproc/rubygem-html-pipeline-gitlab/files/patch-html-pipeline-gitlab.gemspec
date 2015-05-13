--- html-pipeline-gitlab.gemspec.orig	2015-05-12 18:41:42 UTC
+++ html-pipeline-gitlab.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<pry>, ["~> 0.9"])
       s.add_runtime_dependency(%q<html-pipeline>, ["~> 1.11.0"])
       s.add_runtime_dependency(%q<gitlab_emoji>, ["~> 0.1"])
-      s.add_runtime_dependency(%q<sanitize>, ["~> 2.1"])
+      s.add_runtime_dependency(%q<sanitize>, [">= 2.1"])
       s.add_runtime_dependency(%q<actionpack>, ["~> 4"])
       s.add_runtime_dependency(%q<mime-types>, [">= 0"])
     else
