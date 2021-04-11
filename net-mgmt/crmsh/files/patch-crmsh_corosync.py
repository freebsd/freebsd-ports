--- crmsh/corosync.py.orig	2018-04-19 03:47:12 UTC
+++ crmsh/corosync.py
@@ -14,7 +14,7 @@ from .msg import err_buf, common_debug
 
 
 def conf():
-    return os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+    return os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
 
 
 def is_corosync_stack():
