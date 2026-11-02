Description: ssl.wrap_socket() was removed in Python 3.12, so the
  authenticator process (started unless disable_security is set) crashed on
  the first connection and ClientAuth could not authenticate. Use an
  SSLContext with the same behaviour: the server presents its certificate,
  and the client verifies it against the configured certificate without a
  hostname check.
Issue ID: to be filed upstream
Changeset: https://github.com/napalm-automation/napalm-logs/pull/397
TODO: Drop when a release includes #PR 397.

--- napalm_logs/utils/__init__.py.orig	2022-11-08 13:33:16 UTC
+++ napalm_logs/utils/__init__.py
@@ -129,9 +129,12 @@ class ClientAuth:
         else:
             skt_ver = socket.AF_INET
         skt = socket.socket(skt_ver, socket.SOCK_STREAM)
-        self.ssl_skt = ssl.wrap_socket(
-            skt, ca_certs=self.certificate, cert_reqs=ssl.CERT_REQUIRED
-        )
+        # ssl.wrap_socket() was removed in Python 3.12: verify the server
+        # against the certificate, without a hostname check, as before
+        context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
+        context.check_hostname = False
+        context.load_verify_locations(self.certificate)
+        self.ssl_skt = context.wrap_socket(skt)
         try:
             self.ssl_skt.connect((self.address, self.port))
             self.auth_try_id = 0
