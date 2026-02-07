--- oxidized.gemspec.orig      2026-02-04 10:32:45 UTC
+++ oxidized.gemspec
@@ -34,7 +34,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.6".freeze])
   s.add_runtime_dependency(%q<semantic_logger>.freeze, ["~> 4.17.0".freeze])
   s.add_runtime_dependency(%q<slop>.freeze, ["~> 4.6".freeze])
-  s.add_runtime_dependency(%q<syslog>.freeze, ["~> 0.3.0".freeze])
+  s.add_runtime_dependency(%q<syslog>.freeze, [">= 0.3.0".freeze])
   s.add_runtime_dependency(%q<syslog_protocol>.freeze, ["~> 0.9.2".freeze])
   s.add_development_dependency(%q<git>.freeze, [">= 2.0".freeze, "< 3.2.0".freeze])
   s.add_development_dependency(%q<minitest>.freeze, ["~> 5.26.0".freeze])
