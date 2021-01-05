--- trac/util/daemon.py.orig	2020-12-20 02:35:50 UTC
+++ trac/util/daemon.py
@@ -68,12 +68,14 @@ def daemonize(pidfile=None, progname=None, stdin='/dev
     # The process is now daemonized, redirect standard file descriptors
     for stream in sys.stdout, sys.stderr:
         stream.flush()
-    stdin = os.open(stdin, 'rb')
-    stdout = os.open(stdout, 'ab+')
-    stderr = os.open(stderr, 'ab+', 0)
-    os.dup2(stdin.fileno(), sys.stdin.fileno())
-    os.dup2(stdout.fileno(), sys.stdout.fileno())
-    os.dup2(stderr.fileno(), sys.stderr.fileno())
+    stdin = os.open(stdin, os.O_RDONLY)
+    stdout = os.open(stdout,  os.O_RDWR | os.O_APPEND)
+    stderr = os.open(stderr, os.O_RDWR | os.O_APPEND)
+    os.dup2(stdin, sys.stdin.fileno())
+    os.dup2(stdout, sys.stdout.fileno())
+    os.dup2(stderr, sys.stderr.fileno())
+    for fd in stdin, stdout, stderr:
+        os.close(fd)
 
     if pidfile:
         # Register signal handlers to ensure atexit hooks are called on exit
