--- lib/tasks/gitlab/check.rake.orig	2017-03-19 20:06:47 UTC
+++ lib/tasks/gitlab/check.rake
@@ -621,7 +621,7 @@ namespace :gitlab do
     end
 
     def sidekiq_process_count
-      ps_ux, _ = Gitlab::Popen.popen(%W(ps ux))
+      ps_ux, _ = Gitlab::Popen.popen(%W(ps wux))
       ps_ux.scan(/sidekiq \d+\.\d+\.\d+/).count
     end
   end
