
$FreeBSD$

--- psshlib/psshutil.py.orig
+++ psshlib/psshutil.py
@@ -15,7 +15,10 @@
     if not pathnames:
         return lines
     for pathname in pathnames:
-        f = open(pathname)
+        if pathname == "-":
+            f = open("/dev/stdin")
+        else:
+            f = open(pathname)
         for line in f:
             lines.append(line.strip())
         f.close()
