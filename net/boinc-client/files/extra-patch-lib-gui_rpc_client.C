--- lib/gui_rpc_client.C.orig	Thu Mar 17 16:04:53 2005
+++ lib/gui_rpc_client.C	Sun Mar 20 22:32:04 2005
@@ -164,11 +164,11 @@
 }
 
 void PROJECT::clear() {
-    master_url.clear();
+    master_url = "";
     resource_share = 0.0;
-    project_name.clear();
-    user_name.clear();
-    team_name.clear();
+    project_name = "";
+    user_name = "";
+    team_name = "";
     user_total_credit = 0.0;
     user_expavg_credit = 0.0;
     host_total_credit = 0.0;
@@ -209,7 +209,7 @@
 }
 
 void APP::clear() {
-    name.clear();
+    name = "";
     project = NULL;
 }
 
@@ -238,7 +238,7 @@
 }
 
 void APP_VERSION::clear() {
-    app_name.clear();
+    app_name = "";
     version_num = 0;
     app = NULL;
     project = NULL;
@@ -276,8 +276,8 @@
 }
 
 void WORKUNIT::clear() {
-    name.clear();
-    app_name.clear();
+    name = "";
+    app_name = "";
     version_num = 0;
     rsc_fpops_est = 0.0;
     rsc_fpops_bound = 0.0;
@@ -376,9 +376,9 @@
 }
 
 void RESULT::clear() {
-    name.clear();
-    wu_name.clear();
-    project_url.clear();
+    name = "";
+    wu_name = "";
+    project_url = "";
     report_deadline = 0;
     ready_to_report = false;
     got_server_ack = false;
@@ -389,7 +389,7 @@
     signal = 0;
     active_task_state = 0;
     active_task = false;
-    stderr_out.clear();
+    stderr_out = "";
     app_version_num = 0;
     checkpoint_cpu_time = 0.0;
     current_cpu_time = 0.0;
@@ -463,9 +463,9 @@
 }
 
 void FILE_TRANSFER::clear() {
-    name.clear();
-    project_url.clear();
-    project_name.clear();
+    name = "";
+    project_url = "";
+    project_name = "";
     nbytes = 0.0;
     generated_locally = false;
     uploaded = false;
@@ -481,7 +481,7 @@
     bytes_xferred = 0.0;
     file_offset = 0.0;
     xfer_speed = 0.0;
-    hostname.clear();
+    hostname = "";
     project = NULL;
 }
 
@@ -516,10 +516,10 @@
 }
 
 void MESSAGE::clear() {
-    project.clear();
+    project = "";
     priority = 0;
     timestamp = 0;
-    body.clear();
+    body = "";
 }
 
 PROXY_INFO::PROXY_INFO() {
@@ -570,14 +570,14 @@
     use_socks_proxy = false;
     use_http_authentication = false;
     socks_version = 0;
-    socks_server_name.clear();
-    http_server_name.clear();
+    socks_server_name = "";
+    http_server_name = "";
     socks_server_port = 0;
     http_server_port = 0;
-    http_user_name.clear();
-    http_user_passwd.clear();
-    socks5_user_name.clear();
-    socks5_user_passwd.clear();
+    http_user_name = "";
+    http_user_passwd = "";
+    socks5_user_name = "";
+    socks5_user_passwd = "";
 }
 
 HOST_INFO::HOST_INFO() {
