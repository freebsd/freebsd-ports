--- config/boot.rb.orig	2017-05-20 22:05:08 UTC
+++ config/boot.rb
@@ -1,14 +1,14 @@
 ENV['BUNDLE_GEMFILE'] ||= File.expand_path('../Gemfile', __dir__)
 
 require 'bundler/setup' # Set up gems listed in the Gemfile.
-require 'bootsnap'
+#require 'bootsnap'
 
-Bootsnap.setup(
-  cache_dir:            'tmp/cache',
-  development_mode:     ENV['RAILS_ENV'] == 'development',
-  load_path_cache:      true,
-  autoload_paths_cache: true,
-  disable_trace:        true,
-  compile_cache_iseq:   false,
-  compile_cache_yaml:   false
-)
+# Bootsnap.setup(
+#   cache_dir:            'tmp/cache',
+#   development_mode:     ENV['RAILS_ENV'] == 'development',
+#   load_path_cache:      true,
+#   autoload_paths_cache: true,
+#   disable_trace:        true,
+#   compile_cache_iseq:   false,
+#   compile_cache_yaml:   false
+# )
