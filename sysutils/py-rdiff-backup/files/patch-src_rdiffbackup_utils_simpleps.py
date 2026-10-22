--- src/rdiffbackup/utils/simpleps.py.orig	2026-10-22 19:25:02 UTC
+++ src/rdiffbackup/utils/simpleps.py
@@ -50,7 +50,7 @@ def _get_pid_name_ps(pid):
     if os.name == "nt":
         cmd = ("tasklist", "/nh", "/fi", "pid eq {pp}".format(pp=pid))
     else:
-        cmd = ("ps", "-p", str(pid), "-o", "comm=,pid=")
+        cmd = ("ps", "-p", str(pid), "-o", "comm=", "-o", "pid=")
     output = subprocess.run(
         cmd, stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, check=False
     ).stdout.decode().split()
