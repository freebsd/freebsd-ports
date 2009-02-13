
$FreeBSD$

--- psshlib/psshutil.py.orig
+++ psshlib/psshutil.py
@@ -7,7 +7,10 @@
     three arrays: hosts, ports, and users.  These can be used directly
     for all ssh-based commands (e.g., ssh, scp, rsync -e ssh, etc.)
     """
-    f = open(pathname)
+    if pathname == "-":
+        f = open("/dev/stdin")
+    else:
+        f = open(pathname)
     lines = f.readlines()
     lines = map(lambda x: x.strip(), lines)
     addrs = []
