--- crmsh/bootstrap.py.orig	2021-08-12 08:25:27 UTC
+++ crmsh/bootstrap.py
@@ -42,7 +42,7 @@ from . import ocfs2
 LOG_FILE = "/var/log/crmsh/ha-cluster-bootstrap.log"
 CSYNC2_KEY = "/etc/csync2/key_hagroup"
 CSYNC2_CFG = "/etc/csync2/csync2.cfg"
-COROSYNC_AUTH = "/etc/corosync/authkey"
+COROSYNC_AUTH = "%%PREFIX%%/etc/corosync/authkey"
 SYSCONFIG_SBD = "/etc/sysconfig/sbd"
 SYSCONFIG_PCMK = "/etc/sysconfig/pacemaker"
 SYSCONFIG_NFS = "/etc/sysconfig/nfs"
