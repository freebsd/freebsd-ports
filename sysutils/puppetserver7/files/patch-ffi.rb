--- ffi.rb.orig	2019-09-22 21:04:46 UTC
+++ ffi.rb
@@ -125,7 +125,7 @@ module FFI
   # Load all the platform dependent types/consts/struct members
   class Config
     CONFIG = Hash.new
-    begin
+    if File.exist?(File.join(Platform::CONF_DIR, 'platform.conf'))
       File.open(File.join(Platform::CONF_DIR, 'platform.conf'), "r") do |f|
         typedef = "rbx.platform.typedef."
         f.each_line { |line|
@@ -138,7 +138,6 @@ module FFI
           end
         }
       end
-    rescue Errno::ENOENT
     end
   end
 end
