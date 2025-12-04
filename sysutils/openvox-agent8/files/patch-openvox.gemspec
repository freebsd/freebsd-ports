--- openvox.gemspec.orig	2025-08-23 23:48:23 UTC
+++ openvox.gemspec
@@ -21,10 +21,10 @@ Gem::Specification.new do |spec|
   spec.summary = "OpenVox, a community implementation of Puppet -- an automated configuration management tool"
   spec.specification_version = 4
   spec.add_runtime_dependency('base64', '>= 0.1', '< 0.4')
-  spec.add_runtime_dependency('benchmark', '>= 0.3', '< 0.5')
+  spec.add_runtime_dependency('benchmark', '>= 0.3', '< 0.6')
   spec.add_runtime_dependency('concurrent-ruby', '~> 1.0')
   spec.add_runtime_dependency('deep_merge', '~> 1.0')
-  spec.add_runtime_dependency('fast_gettext', '>= 2.1', '< 4')
+  spec.add_runtime_dependency('fast_gettext', '>= 2.1', '< 5')
   spec.add_runtime_dependency('getoptlong', '~> 0.2.0')
   spec.add_runtime_dependency('locale', '~> 2.1')
   spec.add_runtime_dependency('multi_json', '~> 1.13')
