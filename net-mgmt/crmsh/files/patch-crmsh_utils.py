--- crmsh/utils.py.orig	2018-04-19 03:54:07 UTC
+++ crmsh/utils.py
@@ -989,7 +989,7 @@ def cluster_stack():
         return "heartbeat"
     elif is_process("[a]isexec"):
         return "openais"
-    elif os.path.exists("/etc/corosync/corosync.conf") or is_program('corosync-cfgtool'):
+    elif os.path.exists("%%PREFIX%%/etc/corosync/corosync.conf") or is_program('corosync-cfgtool'):
         return "corosync"
     return ""
 
@@ -1551,7 +1551,7 @@ def list_corosync_node_names():
     in corosync.conf
     '''
     try:
-        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
         lines = open(cfg).read().split('\n')
         name_re = re.compile(r'\s*name:\s+(.*)')
         names = []
@@ -1570,7 +1570,7 @@ def list_corosync_nodes():
     in corosync.conf
     '''
     try:
-        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
         lines = open(cfg).read().split('\n')
         addr_re = re.compile(r'\s*ring0_addr:\s+(.*)')
         nodes = []
