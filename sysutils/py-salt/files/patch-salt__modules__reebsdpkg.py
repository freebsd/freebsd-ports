--- salt/modules/freebsdpkg.py.orig	2013-10-30 16:16:31.850225522 +0000
+++ salt/modules/freebsdpkg.py	2013-10-30 16:16:47.868224728 +0000
@@ -27,7 +27,7 @@
     '''
     Looks to see if pkgng is being used by checking if database exists
     '''
-    return os.path.isfile('/var/db/pkg/local.sqlite')
+    return os.path.isfile('/usr/local/etc/pkg.conf')
 
 
 @decorators.memoize
