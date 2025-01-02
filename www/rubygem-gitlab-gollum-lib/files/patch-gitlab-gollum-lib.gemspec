--- gitlab-gollum-lib.gemspec.orig	2025-01-01 11:38:31 UTC
+++ gitlab-gollum-lib.gemspec
@@ -26,8 +26,8 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<rouge>.freeze, ["~> 3.1".freeze])
   s.add_runtime_dependency(%q<nokogiri>.freeze, [">= 1.6.1".freeze, "< 2.0".freeze])
   s.add_runtime_dependency(%q<stringex>.freeze, ["~> 2.6".freeze])
-  s.add_runtime_dependency(%q<sanitize>.freeze, ["~> 6.0".freeze])
-  s.add_runtime_dependency(%q<github-markup>.freeze, ["~> 1.6".freeze])
+  s.add_runtime_dependency(%q<sanitize>.freeze, [">= 6.0".freeze, "< 8".freeze])
+  s.add_runtime_dependency(%q<gitlab-markup>.freeze, ["~> 1.6".freeze])
   s.add_runtime_dependency(%q<gemojione>.freeze, ["~> 3.2".freeze])
   s.add_development_dependency(%q<org-ruby>.freeze, ["~> 0.9.9".freeze])
   s.add_development_dependency(%q<kramdown>.freeze, ["~> 1.6.0".freeze])
