--- python/futures/concurrent/futures/process.py.orig	2017-04-11 04:15:19 UTC
+++ python/futures/concurrent/futures/process.py
@@ -247,7 +247,11 @@ def _check_system_limits():
     _system_limits_checked = True
     try:
         import os
-        nsems_max = os.sysconf("SC_SEM_NSEMS_MAX")
+        if sys.platform.startswith('freebsd'):
+            # sem(4) confuses sysconf(3) on FreeBSD < 11.1
+            nsems_max = -1
+        else:
+            nsems_max = os.sysconf("SC_SEM_NSEMS_MAX")
     except (AttributeError, ValueError):
         # sysconf not available or setting not available
         return
