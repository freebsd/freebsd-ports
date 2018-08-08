--- content/browser/background_fetch/background_fetch_context.cc.orig	2018-08-06 00:37:02.712040000 +0200
+++ content/browser/background_fetch/background_fetch_context.cc	2018-08-06 01:03:47.477355000 +0200
@@ -218,7 +218,8 @@
 
   scheduler_->AddJobController(controller.get());
 
-  job_controllers_.insert({unique_id, std::move(controller)});
+  auto pair = std::make_pair(unique_id, std::move(controller));
+  job_controllers_.insert(std::move(pair));
   std::move(done_closure).Run();
 }
 
