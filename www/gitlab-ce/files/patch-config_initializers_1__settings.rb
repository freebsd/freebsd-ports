--- config/initializers/1_settings.rb.orig	2019-10-22 12:01:49 UTC
+++ config/initializers/1_settings.rb
@@ -178,12 +178,8 @@ Settings.gitlab['email_smime'] = SmimeSignatureSetting
 Settings.gitlab['base_url']   ||= Settings.__send__(:build_base_gitlab_url)
 Settings.gitlab['url']        ||= Settings.__send__(:build_gitlab_url)
 Settings.gitlab['user']       ||= 'git'
-Settings.gitlab['user_home']  ||= begin
-  Etc.getpwnam(Settings.gitlab['user']).dir
-rescue ArgumentError # no user configured
-  '/home/' + Settings.gitlab['user']
-end
-Settings.gitlab['time_zone'] ||= nil
+Settings.gitlab['user_home']  ||= '/usr/home/' + Settings.gitlab['user']
+Settings.gitlab['time_zone']  ||= nil
 Settings.gitlab['signup_enabled'] ||= true if Settings.gitlab['signup_enabled'].nil?
 Settings.gitlab['signin_enabled'] ||= true if Settings.gitlab['signin_enabled'].nil?
 Settings.gitlab['restricted_visibility_levels'] = Settings.__send__(:verify_constant_array, Gitlab::VisibilityLevel, Settings.gitlab['restricted_visibility_levels'], [])
