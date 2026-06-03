--- puppet.gemspec.orig	2024-10-08 21:08:03 UTC
+++ puppet.gemspec
@@ -23,11 +23,11 @@ Gem::Specification.new do |spec|
   spec.add_runtime_dependency('concurrent-ruby', '~> 1.0')
   spec.add_runtime_dependency('deep_merge', '~> 1.0')
   spec.add_runtime_dependency('facter', ['>= 4.3.0', '< 5'])
-  spec.add_runtime_dependency('fast_gettext', '>= 2.1', '< 4')
+  spec.add_runtime_dependency('fast_gettext', '>= 2.1', '< 5')
   spec.add_runtime_dependency('getoptlong', '~> 0.2.0')
   spec.add_runtime_dependency('locale', '~> 2.1')
   spec.add_runtime_dependency('multi_json', '~> 1.13')
-  spec.add_runtime_dependency('puppet-resource_api', '~> 1.5')
+  spec.add_runtime_dependency('puppet-resource_api', '>= 1.5')
   spec.add_runtime_dependency('scanf', '~> 1.0')
   spec.add_runtime_dependency('semantic_puppet', '~> 1.0')
 
