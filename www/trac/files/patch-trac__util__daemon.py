Revert r10799 which breaks tracd startup

beta# /usr/local/etc/rc.d/tracd start
Starting tracd.
Error writing to pid file: IOError: [Errno 2] No such file or directory: '/var/db/trac/redports/tracd.pid'
/usr/local/etc/rc.d/tracd: WARNING: failed to start tracd

See:	http://trac.edgewall.org/changeset/10799/
--- trac/util/daemon.py.orig	2012-02-06 21:53:52.000000000 +0100
+++ trac/util/daemon.py	2012-02-07 10:38:32.414621956 +0100
@@ -44,14 +44,6 @@
                 if e.errno != errno.ESRCH:
                     raise
 
-        # The pid file must be writable
-        try:
-            fileobj = open(pidfile, 'r+')
-            fileobj.close()
-        except IOError, e:
-            from trac.util.text import exception_to_unicode
-            sys.exit('Error writing to pid file: %s' % exception_to_unicode(e))
-
     # Perform first fork
     pid = os.fork()
     if pid > 0:
