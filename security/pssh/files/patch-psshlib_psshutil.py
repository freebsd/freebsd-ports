
$FreeBSD$

--- psshlib/psshutil.py.orig
+++ psshlib/psshutil.py
@@ -1,22 +1,18 @@
 import os, signal, sys
 
-def reaper(signo, frame):
-    while 1:
-        try:
-            pid, status = os.waitpid(-1, os.WNOHANG)
-        except:
-            break
-        if not pid:
-            break
-
 def read_hosts(pathname):
     """
     Read hostfile with lines of the form: host[:port] [login]. Return
     three arrays: hosts, ports, and users.  These can be used directly
     for all ssh-based commands (e.g., ssh, scp, rsync -e ssh, etc.)
+    Empty lines and lines where the first non-blank character is a
+    '#' character are ignored.
     """
     import re
-    f = open(pathname)
+    if pathname == "-":
+	f = open("/dev/stdin")
+    else:
+        f = open(pathname)
     lines = f.readlines()
     lines = map(lambda x: x.strip(), lines)
     addrs = []
@@ -24,7 +20,7 @@
     ports = []
     users = []
     for line in lines:
-        if re.match("^\s+$", line) or len(line) == 0:
+        if re.match("^\s*(#|$)", line):
             continue
         fields = re.split("\s", line)
         if len(fields) == 1:
