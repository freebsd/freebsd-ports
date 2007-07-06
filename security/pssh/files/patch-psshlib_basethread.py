
$FreeBSD$

--- psshlib/basethread.py.orig
+++ psshlib/basethread.py
@@ -1,4 +1,4 @@
-import color, cStringIO, fcntl, os, select, signal, sys, threading, time, Queue
+import color, cStringIO, errno, fcntl, os, select, signal, sys, threading, time, Queue
 from subprocess import Popen, PIPE
 
 class BaseThread(threading.Thread):
@@ -35,7 +35,15 @@
                 timeout = self.flags["timeout"] - (time.time() - start)
                 if timeout <= 0:
                     raise Exception("Timeout")
-                r, w, e = select.select([ cstdout, cstderr ], [], [], timeout)
+                while True:
+                    try:
+                        r, w, e = select.select([ cstdout, cstderr ], [], [], timeout)
+                        break
+                    except select.error, v:
+                        if v[0] == errno.EINTR:
+                            continue
+                        else:
+                            raise 
                 try:
                     for f in r:
                         chunk = f.read()
