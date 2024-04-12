--- vendor/gems/bundler-checksum/bundler-checksum.gemspec.orig	2022-10-18 20:30:55 UTC
+++ vendor/gems/bundler-checksum/bundler-checksum.gemspec
@@ -15,7 +15,7 @@ Gem::Specification.new do |spec|
 
   spec.files         = Dir['bin/*', 'lib/**/*.rb']
   spec.bindir        = 'bin'
-  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
+#  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
   spec.require_paths = ['lib']
 
   spec.add_dependency 'bundler'
