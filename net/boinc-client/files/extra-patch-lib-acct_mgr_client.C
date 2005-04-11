--- lib/acct_mgr_client.C.orig	Sat Mar 12 01:51:33 2005
+++ lib/acct_mgr_client.C	Thu Mar 24 10:12:20 2005
@@ -65,8 +65,8 @@
 }
 
 void ACCT_MGR::clear() {
-    name.clear();
-    url.clear();
+    name = "";
+    url = "";
 }
 
 ACCT_MGR_LOGIN::ACCT_MGR_LOGIN() {
@@ -93,8 +93,8 @@
 }
 
 void ACCT_MGR_LOGIN::clear() {
-    login.clear();
-    password.clear();
+    login = "";
+    password = "";
 }
 
 
