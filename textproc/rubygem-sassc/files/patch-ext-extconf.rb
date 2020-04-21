--- ext/extconf.rb.orig	2020-04-20 21:57:28 UTC
+++ ext/extconf.rb
@@ -29,12 +29,6 @@ end
 # see: https://github.com/sass/sassc-ruby/issues/148
 enable_lto_by_default = (Gem::Platform.local.os == "darwin" && !ENV['NIX_CC'].nil?)
 
-if enable_config('lto', enable_lto_by_default)
-  $CFLAGS << ' -flto'
-  $CXXFLAGS << ' -flto'
-  $LDFLAGS << ' -flto'
-end
-
 # Disable noisy compilation warnings.
 $warnflags = ''
 $CFLAGS.gsub!(/[\s+](-ansi|-std=[^\s]+)/, '')
