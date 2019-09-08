--- ext/extconf.rb.orig	2019-09-07 21:32:44 UTC
+++ ext/extconf.rb
@@ -28,7 +28,7 @@ end
 if enable_config('lto', true)
   $CFLAGS << ' -flto'
   $CXXFLAGS << ' -flto'
-  $LDFLAGS << ' -flto'
+  $LDFLAGS << ' -flto -fuse-ld=lld'
 end
 
 # Disable noisy compilation warnings.
