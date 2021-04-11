--- utils/crm_init.py.orig	2018-04-19 04:05:44 UTC
+++ utils/crm_init.py
@@ -13,7 +13,7 @@ SERVICES = ['sshd', 'ntp', 'corosync', '
 SSH_KEY = os.path.expanduser('~/.ssh/id_rsa')
 CSYNC2_KEY = '/etc/csync2/key_hagroup'
 CSYNC2_CFG = '/etc/csync2/csync2.cfg'
-COROSYNC_CONF = '/etc/corosync/corosync.conf'
+COROSYNC_CONF = '%%PREFIX%%/etc/corosync/corosync.conf'
 SYSCONFIG_SBD = '/etc/sysconfig/sbd'
 SYSCONFIG_FW = '/etc/sysconfig/SuSEfirewall2'
 SYSCONFIG_FW_CLUSTER = '/etc/sysconfig/SuSEfirewall2.d/services/cluster'
@@ -107,7 +107,7 @@ def files_info():
 
 def logrotate_info():
     rc, _, _ = crm_script.call(
-        'grep -r corosync.conf /etc/logrotate.d',
+        'grep -r corosync.conf %%PREFIX%%/etc/logrotate.d',
         shell=True)
     return {'corosync.conf': rc == 0}
 
