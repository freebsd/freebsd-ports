--- lib/gitlab/recaptcha.rb.orig	2017-11-18 21:06:32 UTC
+++ lib/gitlab/recaptcha.rb
@@ -3,8 +3,8 @@ module Gitlab
     def self.load_configurations!
       if current_application_settings.recaptcha_enabled
         ::Recaptcha.configure do |config|
-          config.public_key  = current_application_settings.recaptcha_site_key
-          config.private_key = current_application_settings.recaptcha_private_key
+          config.site_key  = current_application_settings.recaptcha_site_key
+          config.secret_key = current_application_settings.recaptcha_private_key
         end
 
         true
