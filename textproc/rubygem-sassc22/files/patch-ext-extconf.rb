--- ext/extconf.rb.orig	2019-10-20 13:40:05 UTC
+++ ext/extconf.rb
@@ -19,18 +19,6 @@ if enable_config('static-stdlib', false)
   $LDFLAGS << ' -static-libgcc -static-libstdc++'
 end
 
-# Set to false when building binary gems
-if enable_config('march-tune-native', true)
-  $CFLAGS << ' -march=native -mtune=native'
-  $CXXFLAGS << ' -march=native -mtune=native'
-end
-
-if enable_config('lto', true)
-  $CFLAGS << ' -flto'
-  $CXXFLAGS << ' -flto'
-  $LDFLAGS << ' -flto'
-end
-
 # Disable noisy compilation warnings.
 $warnflags = ''
 $CFLAGS.gsub!(/[\s+](-ansi|-std=[^\s]+)/, '')
