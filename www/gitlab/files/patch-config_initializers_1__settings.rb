--- config/initializers/1_settings.rb.orig	2025-02-19 06:08:46 UTC
+++ config/initializers/1_settings.rb
@@ -214,11 +214,7 @@ Settings.gitlab['ssh_user'] ||= Settings.gitlab.user
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
