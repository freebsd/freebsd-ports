--- config/initializers/1_settings.rb.orig	2020-01-31 21:59:11 UTC
+++ config/initializers/1_settings.rb
@@ -179,11 +179,7 @@ Settings.gitlab['email_smime'] = SmimeSignatureSetting
 Settings.gitlab['base_url'] ||= Settings.__send__(:build_base_gitlab_url)
 Settings.gitlab['url'] ||= Settings.__send__(:build_gitlab_url)
 Settings.gitlab['user'] ||= 'git'
-Settings.gitlab['user_home'] ||= begin
-  Etc.getpwnam(Settings.gitlab['user']).dir
-rescue ArgumentError # no user configured
-  '/home/' + Settings.gitlab['user']
-end
+Settings.gitlab['user_home'] ||= '/usr/local/git'
 Settings.gitlab['time_zone'] ||= nil
 Settings.gitlab['signup_enabled'] ||= true if Settings.gitlab['signup_enabled'].nil?
 Settings.gitlab['signin_enabled'] ||= true if Settings.gitlab['signin_enabled'].nil?
