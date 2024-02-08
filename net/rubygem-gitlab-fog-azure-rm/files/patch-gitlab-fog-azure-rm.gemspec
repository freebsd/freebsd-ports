--- gitlab-fog-azure-rm.gemspec.orig	2024-02-27 16:54:02 UTC
+++ gitlab-fog-azure-rm.gemspec
@@ -29,7 +29,7 @@ Gem::Specification.new do |s|
   s.add_development_dependency(%q<simplecov>.freeze, [">= 0".freeze])
   s.add_runtime_dependency(%q<azure-storage-blob>.freeze, ["~> 2.0".freeze])
   s.add_runtime_dependency(%q<azure-storage-common>.freeze, ["~> 2.0".freeze])
-  s.add_runtime_dependency(%q<fog-core>.freeze, ["= 2.1.0".freeze])
+  s.add_runtime_dependency(%q<fog-core>.freeze, [">= 2.1.0".freeze])
   s.add_runtime_dependency(%q<fog-json>.freeze, ["~> 1.2.0".freeze])
   s.add_runtime_dependency(%q<mime-types>.freeze, [">= 0".freeze])
 end
