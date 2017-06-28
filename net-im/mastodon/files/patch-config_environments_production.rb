--- config/environments/production.rb.orig	2017-05-24 01:40:57 UTC
+++ config/environments/production.rb
@@ -104,4 +104,9 @@ Rails.application.configure do
     'X-Content-Type-Options' => 'nosniff',
     'X-XSS-Protection'       => '1; mode=block',
   }
+
+  # Paperclip config:
+  Paperclip.options[:image_magick_path] = "%%PREFIX%%/bin"
+  Paperclip.options[:command_path] = "%%PREFIX%%/bin"
+
 end
