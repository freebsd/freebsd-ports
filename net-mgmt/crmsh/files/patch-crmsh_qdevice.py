--- crmsh/qdevice.py.orig	2023-05-22 21:01:17 UTC
+++ crmsh/qdevice.py
@@ -123,9 +123,9 @@ class QDevice(object):
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
             tls="on", ssh_user=None, cluster_node=None, cmds=None, mode=None, cluster_name=None, is_stage=False):
