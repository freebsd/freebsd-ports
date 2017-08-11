--- paramiko/client.py.orig	2017-07-30 14:38:18 UTC
+++ paramiko/client.py
@@ -331,6 +331,30 @@ class SSHClient (ClosingContextManager):
         t = self._transport = Transport(
             sock, gss_kex=gss_kex, gss_deleg_creds=gss_deleg_creds)
         t.use_compression(compress=compress)
+
+        if port == SSH_PORT:
+            server_hostkey_name = hostname
+        else:
+            server_hostkey_name = "[%s]:%d" % (hostname, port)
+
+        # if we already have a host key stored, change our key preference
+        known_host_keys = {}
+        known_host_keys.update(
+            self._system_host_keys.get(server_hostkey_name, {})
+        )
+        known_host_keys.update(
+            self.get_host_keys().get(server_hostkey_name, {})
+        )
+
+        if known_host_keys:
+            # order the keys as follows: known keys in preferred-keys order,
+            # then unknown keys in preferred-keys order
+            valid_known_keys = [k for k in t._preferred_keys
+                                if k in known_host_keys]
+            t._preferred_keys = (valid_known_keys
+                                 + [k for k in t._preferred_keys
+                                    if k not in valid_known_keys])
+
         if gss_kex and gss_host is None:
             t.set_gss_host(hostname)
         elif gss_kex and gss_host is not None:
@@ -344,10 +368,6 @@ class SSHClient (ClosingContextManager):
         if auth_timeout is not None:
             t.auth_timeout = auth_timeout
 
-        if port == SSH_PORT:
-            server_hostkey_name = hostname
-        else:
-            server_hostkey_name = "[%s]:%d" % (hostname, port)
         our_server_keys = None
 
         # If GSS-API Key Exchange is performed we are not required to check the
