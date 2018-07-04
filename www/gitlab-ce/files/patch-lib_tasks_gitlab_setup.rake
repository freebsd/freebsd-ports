--- lib/tasks/gitlab/setup.rake.orig	2018-06-21 08:18:34 UTC
+++ lib/tasks/gitlab/setup.rake
@@ -1,7 +1,8 @@
 namespace :gitlab do
   desc "GitLab | Setup production application"
   task setup: :gitlab_environment do
-    check_gitaly_connection
+    # Remove this check, see https://gitlab.com/gitlab-org/gitlab-ce/issues/47483
+    #check_gitaly_connection
     setup_db
   end
 
