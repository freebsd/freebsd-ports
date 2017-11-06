--- config/initializers/1_settings.rb.orig	2017-08-09 13:53:30 UTC
+++ config/initializers/1_settings.rb
@@ -216,12 +216,8 @@ Settings.gitlab['email_subject_suffix'] 
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
