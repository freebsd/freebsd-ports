--- oxidized.gemspec.orig	2026-03-31 13:18:13 UTC
+++ oxidized.gemspec
@@ -33,7 +33,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.6".freeze])
   s.add_runtime_dependency(%q<semantic_logger>.freeze, ["~> 4.17".freeze])
   s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.6".freeze])
-  s.add_runtime_dependency(%q<syslog>.freeze, ["~> 0.3".freeze])
+  s.add_runtime_dependency(%q<syslog>.freeze, [">= 0.3".freeze])
   s.add_runtime_dependency(%q<syslog_protocol>.freeze, ["~> 0.9".freeze])
   s.add_development_dependency(%q<minitest>.freeze, [">= 5.18".freeze, "< 7".freeze])
   s.add_development_dependency(%q<mocha>.freeze, [">= 2.1".freeze, "< 4".freeze])
