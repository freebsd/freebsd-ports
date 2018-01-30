--- config/boot.rb.orig	2018-01-24 12:29:46 UTC
+++ config/boot.rb
@@ -4,7 +4,7 @@ require 'bundler/setup' # Set up gems li
 require 'bootsnap'
 
 Bootsnap.setup(
-  cache_dir:            'tmp/cache',
+  cache_dir:            '/var/cache/mastodon',
   development_mode:     ENV['RAILS_ENV'] == 'development',
   load_path_cache:      true,
   autoload_paths_cache: true,
