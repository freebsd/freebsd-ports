Description: Store the GSSAPI state on flask.g instead of _request_ctx_stack
  (removed in Flask 3.0) and take the KrbError message from exc.args
  instead of exc.message. Use logger.warning() instead of the deprecated
  logger.warn().
Issue ID: none
Changeset: none
TODO: FreeBSD-only (the project requires a CLA for contributions); drop once
  a release includes an equivalent fix.

--- flask_kerberos.py.orig	2014-08-27 01:50:43 UTC
+++ flask_kerberos.py
@@ -1,7 +1,7 @@
 import kerberos
 
 from flask import Response
-from flask import _request_ctx_stack as stack
+from flask import g
 from flask import make_response
 from flask import request
 from functools import wraps
@@ -27,12 +27,16 @@ def init_kerberos(app, service='HTTP', h
     _SERVICE_NAME = "%s@%s" % (service, hostname)
 
     if 'KRB5_KTNAME' not in environ:
-        app.logger.warn("Kerberos: set KRB5_KTNAME to your keytab file")
+        app.logger.warning("Kerberos: set KRB5_KTNAME to your keytab file")
     else:
         try:
             principal = kerberos.getServerPrincipalDetails(service, hostname)
         except kerberos.KrbError as exc:
-            app.logger.warn("Kerberos: %s" % exc.message[0])
+            # pykerberos raises KrbError((message, code))
+            msg = exc.args[0]
+            if isinstance(msg, tuple):
+                msg = msg[0]
+            app.logger.warning("Kerberos: %s" % msg)
         else:
             app.logger.info("Kerberos: server is %s" % principal)
 
@@ -65,7 +69,7 @@ def _gssapi_authenticate(token):
     @rtype: int or None
     '''
     state = None
-    ctx = stack.top
+    ctx = g
     try:
         rc, state = kerberos.authGSSServerInit(_SERVICE_NAME)
         if rc != kerberos.AUTH_GSS_COMPLETE:
@@ -101,7 +105,7 @@ def requires_authentication(function):
     def decorated(*args, **kwargs):
         header = request.headers.get("Authorization")
         if header:
-            ctx = stack.top
+            ctx = g
             token = ''.join(header.split()[1:])
             rc = _gssapi_authenticate(token)
             if rc == kerberos.AUTH_GSS_COMPLETE:
