--- gitlab-gollum-lib.gemspec.orig	2020-09-22 16:42:50 UTC
+++ gitlab-gollum-lib.gemspec
@@ -28,8 +28,8 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<rouge>.freeze, ["~> 3.1"])
       s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.6.1", "< 2.0"])
       s.add_runtime_dependency(%q<stringex>.freeze, ["~> 2.6"])
-      s.add_runtime_dependency(%q<sanitize>.freeze, ["~> 4.6.4"])
-      s.add_runtime_dependency(%q<github-markup>.freeze, ["~> 1.6"])
+      s.add_runtime_dependency(%q<sanitize>.freeze, ["~> 5.2.1"])
+      s.add_runtime_dependency(%q<gitlab-markup>.freeze, ["~> 1.6"])
       s.add_runtime_dependency(%q<gemojione>.freeze, ["~> 3.2"])
       s.add_development_dependency(%q<org-ruby>.freeze, ["~> 0.9.9"])
       s.add_development_dependency(%q<kramdown>.freeze, ["~> 1.6.0"])
