--- psshlib/psshutil.py.orig
+++ psshlib/psshutil.py
@@ -27,7 +27,10 @@
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
