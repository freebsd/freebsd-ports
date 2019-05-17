# HTTP20Connection: Fix use of ENABLE_PUSH
# https://github.com/Lukasa/hyper/pull/402

--- hyper/http20/connection.py.orig	2019-05-17 10:15:20 UTC
+++ hyper/http20/connection.py
@@ -7,7 +7,7 @@ Objects that build hyper's connection-level HTTP/2 abs
 """
 import h2.connection
 import h2.events
-import h2.settings
+from h2.settings import SettingCodes
 
 from ..compat import ssl
 from ..tls import wrap_socket, H2_NPN_PROTOCOLS, H2C_PROTOCOL
@@ -403,7 +403,7 @@ class HTTP20Connection(object):
         with self._conn as conn:
             conn.initiate_upgrade_connection()
             conn.update_settings(
-                {h2.settings.ENABLE_PUSH: int(self._enable_push)}
+                {SettingCodes.ENABLE_PUSH: int(self._enable_push)}
             )
         self._send_outstanding_data()
 
@@ -424,7 +424,7 @@ class HTTP20Connection(object):
         with self._conn as conn:
             conn.initiate_connection()
             conn.update_settings(
-                {h2.settings.ENABLE_PUSH: int(self._enable_push)}
+                {SettingCodes.ENABLE_PUSH: int(self._enable_push)}
             )
         self._send_outstanding_data()
 
