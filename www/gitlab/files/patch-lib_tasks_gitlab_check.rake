--- lib/tasks/gitlab/check.rake.orig	2017-06-07 20:58:14 UTC
+++ lib/tasks/gitlab/check.rake
@@ -617,7 +617,7 @@ namespace :gitlab do
     end
 
     def sidekiq_process_count
-      ps_ux, _ = Gitlab::Popen.popen(%w(ps ux))
+      ps_ux, _ = Gitlab::Popen.popen(%W(ps wux))
       ps_ux.scan(/sidekiq \d+\.\d+\.\d+/).count
     end
   end
