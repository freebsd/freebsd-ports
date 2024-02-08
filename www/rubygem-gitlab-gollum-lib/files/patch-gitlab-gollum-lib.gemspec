--- gitlab-gollum-lib.gemspec.orig	2024-02-27 16:56:28 UTC
+++ gitlab-gollum-lib.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.6.1".freeze, "< 2.0".freeze])
   s.add_runtime_dependency(%q<stringex>.freeze, ["~> 2.6".freeze])
   s.add_runtime_dependency(%q<sanitize>.freeze, ["~> 6.0".freeze])
-  s.add_runtime_dependency(%q<github-markup>.freeze, ["~> 1.6".freeze])
+  s.add_runtime_dependency(%q<gitlab-markup>.freeze, ["~> 1.6".freeze])
   s.add_runtime_dependency(%q<gemojione>.freeze, ["~> 3.2".freeze])
   s.add_development_dependency(%q<org-ruby>.freeze, ["~> 0.9.9".freeze])
   s.add_development_dependency(%q<kramdown>.freeze, ["~> 1.6.0".freeze])
