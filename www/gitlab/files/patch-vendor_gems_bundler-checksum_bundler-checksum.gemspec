--- vendor/gems/bundler-checksum/bundler-checksum.gemspec.orig	2024-07-09 07:11:30 UTC
+++ vendor/gems/bundler-checksum/bundler-checksum.gemspec
@@ -14,8 +14,7 @@ Gem::Specification.new do |spec|
   spec.license       = 'MIT'
 
   spec.files         = Dir['bin/*', 'lib/**/*.rb']
-  spec.bindir        = 'bin'
-  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
+  #spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
   spec.require_paths = ['lib']
 
   spec.add_dependency 'bundler'
