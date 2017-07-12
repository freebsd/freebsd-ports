--- config/environments/production.rb.orig	2017-07-07 14:09:38 UTC
+++ config/environments/production.rb
@@ -98,4 +98,9 @@ Rails.application.configure do
     'X-Content-Type-Options' => 'nosniff',
     'X-XSS-Protection'       => '1; mode=block',
   }
+
+  # Paperclip config:
+  Paperclip.options[:image_magick_path] = "%%PREFIX%%/bin"
+  Paperclip.options[:command_path] = "%%PREFIX%%/bin"
+
 end
