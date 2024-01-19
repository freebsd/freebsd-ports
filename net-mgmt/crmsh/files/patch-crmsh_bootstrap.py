--- crmsh/bootstrap.py.orig	2023-03-30 02:10:16 UTC
+++ crmsh/bootstrap.py
@@ -52,7 +52,7 @@ CSYNC2_CFG = "/etc/csync2/csync2.cfg"
 
 CSYNC2_KEY = "/etc/csync2/key_hagroup"
 CSYNC2_CFG = "/etc/csync2/csync2.cfg"
-COROSYNC_AUTH = "/etc/corosync/authkey"
+COROSYNC_AUTH = "%%PREFIX%%/etc/corosync/authkey"
 CRM_CFG = "/etc/crm/crm.conf"
 PROFILES_FILE = "/etc/crm/profiles.yml"
 SYSCONFIG_SBD = "/etc/sysconfig/sbd"
