--- src/common/connection.py.orig	2013-03-17 21:55:32.000000000 +0400
+++ src/common/connection.py	2013-05-01 18:47:51.000000000 +0400
@@ -1331,7 +1331,7 @@
                     certificate=con.Connection.ssl_certificate[i]))
                 return True
             i += 1
-        if hasattr(con.Connection, 'ssl_fingerprint_sha1'):
+        if con.Connection.ssl_fingerprint_sha1:
             saved_fingerprint = gajim.config.get_per('accounts', self.name,
                 'ssl_fingerprint_sha1')
             if saved_fingerprint:
