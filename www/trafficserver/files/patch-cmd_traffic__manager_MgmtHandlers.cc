--- cmd/traffic_manager/MgmtHandlers.cc.orig	2016-07-11 23:03:32 UTC
+++ cmd/traffic_manager/MgmtHandlers.cc
@@ -268,7 +268,7 @@ mgmt_synthetic_main(void *)
     } else {
       ink_thread thrId = ink_thread_create(synthetic_thread, (void *)&clientFD, 1);
 
-      if (thrId <= 0) {
+      if (thrId == 0) {
         mgmt_log(stderr, "[SyntheticHealthServer] Failed to create worker thread");
       }
     }
