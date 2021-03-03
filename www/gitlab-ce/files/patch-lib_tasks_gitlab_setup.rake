--- lib/tasks/gitlab/setup.rake.orig	2021-02-19 09:35:35 UTC
+++ lib/tasks/gitlab/setup.rake
@@ -3,7 +3,8 @@
 namespace :gitlab do
   desc "GitLab | Setup production application"
   task setup: :gitlab_environment do
-    check_gitaly_connection
+    # Remove this check, see https://gitlab.com/gitlab-org/gitlab-ce/issues/47483
+    #check_gitaly_connection
     setup_db
   end
 
