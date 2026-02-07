--- salt/utils/process.py.orig	2024-07-29 07:51:58 UTC
+++ salt/utils/process.py
@@ -59,7 +59,10 @@ def appendproctitle(name):
         current = setproctitle.getproctitle()
         if current.strip().endswith("MainProcess"):
             current, _ = current.rsplit("MainProcess", 1)
-        setproctitle.setproctitle(f"{current.rstrip()} {name}")
+        if len(current) > 0:
+            setproctitle.setproctitle(f"{current.rstrip()} {name}")
+        else:
+            setproctitle.setproctitle(name)


 def daemonize(redirect_out=True):
