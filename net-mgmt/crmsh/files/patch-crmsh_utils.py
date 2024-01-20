--- crmsh/utils.py.orig	2024-01-09 08:38:25 UTC
+++ crmsh/utils.py
@@ -1564,7 +1564,7 @@ def get_pcmk_version():
 
 
 def get_pcmk_version():
-    cmd = "/usr/sbin/pacemakerd --version"
+    cmd = "%%PREFIX%%/sbin/pacemakerd --version"
     out = sh.cluster_shell().get_stdout_or_raise_error(cmd)
     version = out.split()[1]
     logger.debug("Found pacemaker version: %s", version)
@@ -1725,7 +1725,7 @@ def list_corosync_node_names():
     in corosync.conf
     '''
     try:
-        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
         lines = open(cfg).read().split('\n')
         name_re = re.compile(r'\s*name:\s+(.*)')
         names = []
@@ -1744,7 +1744,7 @@ def list_corosync_nodes():
     in corosync.conf
     '''
     try:
-        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '/etc/corosync/corosync.conf')
+        cfg = os.getenv('COROSYNC_MAIN_CONFIG_FILE', '%%PREFIX%%/etc/corosync/corosync.conf')
         lines = open(cfg).read().split('\n')
         addr_re = re.compile(r'\s*ring0_addr:\s+(.*)')
         nodes = []
