--- puppet.gemspec.orig	2024-06-17 03:44:36 UTC
+++ puppet.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |spec|
   spec.add_runtime_dependency(%q<facter>, ["> 2.0.1", "< 5"])
   spec.add_runtime_dependency(%q<hiera>, [">= 3.2.1", "< 4"])
   spec.add_runtime_dependency(%q<semantic_puppet>, "~> 1.0")
-  spec.add_runtime_dependency(%q<fast_gettext>, ">= 1.1", "< 3")
+  spec.add_runtime_dependency(%q<fast_gettext>, ">= 1.1", "< 4")
   spec.add_runtime_dependency(%q<locale>, "~> 2.1")
   spec.add_runtime_dependency(%q<multi_json>, "~> 1.10")
   spec.add_runtime_dependency(%q<puppet-resource_api>, "~> 1.5")
