--- scripts/health/collect.py.orig	2018-04-19 04:04:24 UTC
+++ scripts/health/collect.py
@@ -67,7 +67,7 @@ def disk_info():
 FILES = [
     '/etc/csync2/key_hagroup',
     '/etc/csync2/csync2.cfg',
-    '/etc/corosync/corosync.conf',
+    '%%PREFIX%%/etc/corosync/corosync.conf',
     '/etc/sysconfig/sbd',
     '/etc/sysconfig/SuSEfirewall2',
     '/etc/sysconfig/SuSEfirewall2.d/services/cluster'
