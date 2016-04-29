--- config/initializers/1_settings.rb.orig	2016-04-22 10:01:37 UTC
+++ config/initializers/1_settings.rb
@@ -167,11 +167,7 @@ Settings.gitlab['email_reply_to'] ||= EN
 Settings.gitlab['base_url']   ||= Settings.send(:build_base_gitlab_url)
 Settings.gitlab['url']        ||= Settings.send(:build_gitlab_url)
 Settings.gitlab['user']       ||= 'git'
-Settings.gitlab['user_home']  ||= begin
-  Etc.getpwnam(Settings.gitlab['user']).dir
-rescue ArgumentError # no user configured
-  '/home/' + Settings.gitlab['user']
-end
+Settings.gitlab['user_home']  ||= '/home/' + Settings.gitlab['user']
 Settings.gitlab['time_zone']  ||= nil
 Settings.gitlab['signup_enabled'] ||= true if Settings.gitlab['signup_enabled'].nil?
 Settings.gitlab['signin_enabled'] ||= true if Settings.gitlab['signin_enabled'].nil?
