--- crmsh/corosync.py.orig	2023-03-30 02:10:16 UTC
+++ crmsh/corosync.py
@@ -22,7 +22,7 @@ def conf():
 
 
 def conf():
-    return os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+    return os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
 
 
 def check_tools():
