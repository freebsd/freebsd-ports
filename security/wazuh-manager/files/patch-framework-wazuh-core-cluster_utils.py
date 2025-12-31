--- framework/wazuh/core/cluster/utils.py	2025-12-30 23:32:30.875588000 -0800
+++ framework/wazuh/core/cluster/utils.py	2025-12-30 23:33:42.825809000 -0800
@@ -11,6 +11,7 @@
 import socket
 import time
 import typing
+import subprocess
 from contextvars import ContextVar
 from functools import lru_cache
 from glob import glob
@@ -282,7 +283,7 @@
             # it means each process crashed and was not able to remove its own pidfile.
             data[process] = 'failed'
             for pid in pidfile:
-                if os.path.exists(os.path.join(proc_path, pidfile_regex.match(pid).group(1))):
+                if _check_pid_as_superman(pidfile_regex.match(pid).group(1)):
                     data[process] = 'running'
                     break
 
@@ -291,6 +292,13 @@
 
     return data
 
+def _check_pid_as_superman(pid):
+    try:
+        subprocess.check_call(["/var/ossec/libexec/check_pid", pid])
+    except subprocess.CalledProcessError as e:
+        return False
+ 
+    return True
 
 def get_cluster_status() -> typing.Dict:
     """Get cluster status.
