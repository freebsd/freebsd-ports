--- api/boinc_api.C.orig	Sun Sep  5 19:28:46 2004
+++ api/boinc_api.C	Thu Dec  9 10:22:30 2004
@@ -116,7 +116,7 @@
     options.handle_trickle_ups = true;
     options.handle_trickle_downs = true;
     options.handle_process_control = true;
-    options.send_status_msgs = true;
+    options.send_status_msgs = false;
     options.direct_process_action = true;
     return boinc_init_options(options);
 }
