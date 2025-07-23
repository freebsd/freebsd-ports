--- puppet.gemspec.orig	2025-07-23 00:05:26 UTC
+++ puppet.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |spec|
   spec.add_runtime_dependency('concurrent-ruby', '~> 1.0')
   spec.add_runtime_dependency('deep_merge', '~> 1.0')
   spec.add_runtime_dependency('facter', ['>= 4.3.0', '< 5'])
-  spec.add_runtime_dependency('fast_gettext', '>= 2.1', '< 4')
+  spec.add_runtime_dependency('fast_gettext', '>= 2.1', '< 5')
   spec.add_runtime_dependency('getoptlong', '~> 0.2.0')
   spec.add_runtime_dependency('locale', '~> 2.1')
   spec.add_runtime_dependency('multi_json', '~> 1.13')
