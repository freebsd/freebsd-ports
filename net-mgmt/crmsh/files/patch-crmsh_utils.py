--- crmsh/utils.py.orig	2021-08-12 08:25:45 UTC
+++ crmsh/utils.py
@@ -1667,7 +1667,7 @@ def list_corosync_node_names():
     in corosync.conf
     '''
     try:
-        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
         lines = open(cfg).read().split('\n')
         name_re = re.compile(r'\s*name:\s+(.*)')
         names = []
@@ -1686,7 +1686,7 @@ def list_corosync_nodes():
     in corosync.conf
     '''
     try:
-        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
         lines = open(cfg).read().split('\n')
         addr_re = re.compile(r'\s*ring0_addr:\s+(.*)')
         nodes = []
