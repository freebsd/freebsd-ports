--- config/initializers/1_settings.rb.orig	2020-04-21 23:01:33 UTC
+++ config/initializers/1_settings.rb
@@ -173,11 +173,7 @@ Settings.gitlab['url'] ||= Settings.__send__(:build_gi
 Settings.gitlab['user'] ||= 'git'
 # External configuration may cause the ssh user to differ from the GitLab user
 Settings.gitlab['ssh_user'] ||= Settings.gitlab.user
-Settings.gitlab['user_home'] ||= begin
-  Etc.getpwnam(Settings.gitlab['user']).dir
-rescue ArgumentError # no user configured
-  '/home/' + Settings.gitlab['user']
-end
+Settings.gitlab['user_home'] ||= '/usr/local/git'
 Settings.gitlab['time_zone'] ||= nil
 Settings.gitlab['signup_enabled'] ||= true if Settings.gitlab['signup_enabled'].nil?
 Settings.gitlab['signin_enabled'] ||= true if Settings.gitlab['signin_enabled'].nil?
