--- setup.py.orig	2014-10-21 10:32:31 UTC
+++ setup.py
@@ -48,5 +48,4 @@ as LDAP.''',
                                'nss_cache.util',
                                'nss_cache.update',
                                'nss_cache.sources'],
-                     scripts=['nsscache'],
-                     data_files=[('/etc', ['nsscache.conf'])])
+                     scripts=['nsscache'])
