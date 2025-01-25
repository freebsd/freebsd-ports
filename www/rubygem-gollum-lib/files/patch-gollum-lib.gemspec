--- gollum-lib.gemspec.orig	2024-08-15 15:48:00 UTC
+++ gollum-lib.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<rouge>.freeze, ["~> 3.1".freeze])
   s.add_runtime_dependency(%q<nokogiri>.freeze, ["~> 1.8".freeze])
   s.add_runtime_dependency(%q<loofah>.freeze, ["~> 2.3".freeze])
-  s.add_runtime_dependency(%q<github-markup>.freeze, ["~> 4.0".freeze])
+  s.add_runtime_dependency(%q<github-markup>.freeze, [">= 4.0".freeze])
   s.add_runtime_dependency(%q<gemojione>.freeze, ["~> 4.1".freeze])
   s.add_runtime_dependency(%q<twitter-text>.freeze, ["= 1.14.7".freeze])
   s.add_development_dependency(%q<org-ruby>.freeze, ["~> 0.9.9".freeze])
