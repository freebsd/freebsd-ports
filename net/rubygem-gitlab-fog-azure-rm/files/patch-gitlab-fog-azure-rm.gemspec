--- gitlab-fog-azure-rm.gemspec.orig	2022-08-12 13:22:30 UTC
+++ gitlab-fog-azure-rm.gemspec
@@ -32,7 +32,7 @@ Gem::Specification.new do |s|
     s.add_development_dependency(%q<simplecov>.freeze, [">= 0"])
     s.add_runtime_dependency(%q<azure-storage-blob>.freeze, ["~> 2.0"])
     s.add_runtime_dependency(%q<azure-storage-common>.freeze, ["~> 2.0"])
-    s.add_runtime_dependency(%q<fog-core>.freeze, ["= 2.1.0"])
+    s.add_runtime_dependency(%q<fog-core>.freeze, [">= 2.1.0"])
     s.add_runtime_dependency(%q<fog-json>.freeze, ["~> 1.2.0"])
     s.add_runtime_dependency(%q<mime-types>.freeze, [">= 0"])
     s.add_runtime_dependency(%q<ms_rest_azure>.freeze, ["~> 0.12.0"])
@@ -44,7 +44,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<simplecov>.freeze, [">= 0"])
     s.add_dependency(%q<azure-storage-blob>.freeze, ["~> 2.0"])
     s.add_dependency(%q<azure-storage-common>.freeze, ["~> 2.0"])
-    s.add_dependency(%q<fog-core>.freeze, ["= 2.1.0"])
+    s.add_dependency(%q<fog-core>.freeze, [">= 2.1.0"])
     s.add_dependency(%q<fog-json>.freeze, ["~> 1.2.0"])
     s.add_dependency(%q<mime-types>.freeze, [">= 0"])
     s.add_dependency(%q<ms_rest_azure>.freeze, ["~> 0.12.0"])
