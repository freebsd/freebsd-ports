--- lib/gitlab/recaptcha.rb.orig	2017-11-14 20:51:25 UTC
+++ lib/gitlab/recaptcha.rb
@@ -5,8 +5,8 @@ module Gitlab
     def self.load_configurations!
       if current_application_settings.recaptcha_enabled
         ::Recaptcha.configure do |config|
-          config.public_key  = current_application_settings.recaptcha_site_key
-          config.private_key = current_application_settings.recaptcha_private_key
+          config.site_key  = current_application_settings.recaptcha_site_key
+          config.secret_key = current_application_settings.recaptcha_private_key
         end
 
         true
