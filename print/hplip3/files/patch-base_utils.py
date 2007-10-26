--- base/utils.py.orig	Wed Oct 10 00:23:07 2007
+++ base/utils.py	Wed Oct 10 00:27:04 2007
@@ -54,6 +54,50 @@
 
     return callable
 
+# For pidfile locking (must be "static" and global to the whole app)
+prv_pidfile = None
+prv_pidfile_name = ""
+
+def get_pidfile_lock (a_pidfile_name=""):
+    """ Call this to either lock the pidfile, or to update it after a fork()
+        Credit: Henrique M. Holschuh <hmh@debian.org>
+    """
+    global prv_pidfile
+    global prv_pidfile_name
+    if prv_pidfile_name == "":
+        try:
+            prv_pidfile_name = a_pidfile_name
+            prv_pidfile = os.fdopen(os.open(prv_pidfile_name, os.O_RDWR | os.O_CREAT, 0644), 'r+')
+            fcntl.fcntl(prv_pidfile.fileno(), fcntl.F_SETFD, fcntl.FD_CLOEXEC)
+            while 1:
+                try:
+                    fcntl.flock(prv_pidfile.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
+                except (OSError, IOError), e:
+                    if e.errno == errno.EINTR:
+                        continue
+                    elif e.errno == errno.EWOULDBLOCK:
+                        try:
+                            prv_pidfile.seek(0)
+                            otherpid = int(prv_pidfile.readline(), 10)
+                            sys.stderr.write ("can't lock %s, running daemon's pid may be %d\n" % (prv_pidfile_name, otherpid))
+                        except (OSError, IOError), e:
+                            sys.stderr.write ("error reading pidfile %s: (%d) %s\n" % (prv_pidfile_name, e.errno, e.strerror))
+
+                        sys.exit(1)
+                    sys.stderr.write ("can't lock %s: (%d) %s\n" % (prv_pidfile_name, e.errno, e.strerror))
+                    sys.exit(1)
+                break
+        except (OSError, IOError), e:
+            sys.stderr.write ("can't open pidfile %s: (%d) %s\n" % (prv_pidfile_name, e.errno, e.strerror))
+            sys.exit(1)
+    try:
+        prv_pidfile.seek(0)
+        prv_pidfile.write("%d\n" % (os.getpid()))
+        prv_pidfile.flush()
+        prv_pidfile.truncate()
+    except (OSError, IOError), e:
+        log.error("can't update pidfile %s: (%d) %s\n" % (prv_pidfile_name, e.errno, e.strerror))
+
 def daemonize (stdin='/dev/null', stdout='/dev/null', stderr='/dev/null'):
     """
     Credit: Jürgen Hermann, Andy Gimblett, and Noah Spurrier
