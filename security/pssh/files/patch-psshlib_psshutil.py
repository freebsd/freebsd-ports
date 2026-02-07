--- psshlib/psshutil.py.orig	2020-04-05 06:12:36 UTC
+++ psshlib/psshutil.py
@@ -28,7 +28,10 @@ def read_host_file(path, host_glob, default_user=None,
     Returns a list of (host, port, user) triples.
     """
     lines = []
-    f = open(path)
+    if path == "-":
+        f = open("/dev/stdin")
+    else:
+        f = open(path)
     for line in f:
         lines.append(line.strip())
     f.close()
