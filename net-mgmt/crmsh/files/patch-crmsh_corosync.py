--- crmsh/corosync.py.orig	2021-08-12 08:25:33 UTC
+++ crmsh/corosync.py
@@ -15,7 +15,7 @@ from .msg import err_buf, common_debug
 
 
 def conf():
-    return os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+    return os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
 
 
 def check_tools():
@@ -178,9 +178,9 @@ class QDevice(object):
     qnetd_cacert_filename = "qnetd-cacert.crt"
     qdevice_crq_filename = "qdevice-net-node.crq"
     qdevice_p12_filename = "qdevice-net-node.p12"
-    qnetd_path = "/etc/corosync/qnetd"
-    qdevice_path = "/etc/corosync/qdevice/net"
-    qdevice_db_path = "/etc/corosync/qdevice/net/nssdb"
+    qnetd_path = "%%PREFIX%%/etc/corosync/qnetd"
+    qdevice_path = "%%PREFIX%%/etc/corosync/qdevice/net"
+    qdevice_db_path = "%%PREFIX%%/etc/corosync/qdevice/net/nssdb"
 
     def __init__(self, qnetd_addr, port=5403, algo="ffsplit", tie_breaker="lowest",
             tls="on", cluster_node=None, cmds=None, mode=None):
