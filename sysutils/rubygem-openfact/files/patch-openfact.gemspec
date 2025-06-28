--- openfact.gemspec.orig	2025-06-28 02:21:18 UTC
+++ openfact.gemspec
@@ -32,6 +32,6 @@ Gem::Specification.new do |s|
   s.add_development_dependency(%q<webmock>.freeze, ["~> 3.12".freeze])
   s.add_development_dependency(%q<yard>.freeze, ["~> 0.9".freeze])
   s.add_runtime_dependency(%q<hocon>.freeze, ["~> 1.3".freeze])
-  s.add_runtime_dependency(%q<thor>.freeze, [">= 1.0.1".freeze, "< 1.3".freeze])
+  s.add_runtime_dependency(%q<thor>.freeze, [">= 1.0.1".freeze, "< 2".freeze])
 end
 
