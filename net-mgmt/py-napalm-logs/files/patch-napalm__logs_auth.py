Description: ssl.wrap_socket() was removed in Python 3.12, so the
  authenticator process (started unless disable_security is set) crashed on
  the first connection and ClientAuth could not authenticate. Use an
  SSLContext with the same behaviour: the server presents its certificate,
  and the client verifies it against the configured certificate without a
  hostname check.
Issue ID: to be filed upstream
Changeset: https://github.com/napalm-automation/napalm-logs/pull/397
TODO: Drop when a release includes PR #397.

--- napalm_logs/auth.py.orig	2022-11-08 13:33:16 UTC
+++ napalm_logs/auth.py
@@ -176,6 +176,9 @@ class NapalmLogsAuthProc(NapalmLogsProc)
             AUTH_MAX_CONN,
         )
         self.socket.listen(AUTH_MAX_CONN)
+        # ssl.wrap_socket() was removed in Python 3.12
+        context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
+        context.load_cert_chain(self.certificate, self.keyfile)
         thread = threading.Thread(
             target=self._suicide_when_without_parent, args=(os.getppid(),)
         )
@@ -185,12 +188,7 @@ class NapalmLogsAuthProc(NapalmLogsProc)
         while self.__up:
             try:
                 (clientsocket, address) = self.socket.accept()
-                wrapped_auth_skt = ssl.wrap_socket(
-                    clientsocket,
-                    server_side=True,
-                    certfile=self.certificate,
-                    keyfile=self.keyfile,
-                )
+                wrapped_auth_skt = context.wrap_socket(clientsocket, server_side=True)
             except ssl.SSLError:
                 log.exception("SSL error", exc_info=True)
                 continue
