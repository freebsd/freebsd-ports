--- ipapython/ipaldap.py.orig	2026-01-16 09:23:32 UTC
+++ ipapython/ipaldap.py
@@ -1271,6 +1271,23 @@ class LDAPClient:
             else:
                 auth_tokens = SASL_GSSAPI
             self._flush_schema()
+            # IPA_FREEBSD_CCACHE_FIX: On FreeBSD the cyrus-sasl GSSAPI plugin
+            # in the long-running mod_wsgi process does not honour the
+            # per-request KRB5CCNAME, so it binds with the wrong (HTTP
+            # service) or an empty credential. Point GSSAPI at the intended
+            # ccache explicitly via gss_krb5_ccache_name (thread-local;
+            # WSGIDaemonProcess runs with threads=1).
+            import os as _os
+            import ctypes as _ct
+            _cc = _os.environ.get('KRB5CCNAME')
+            if _cc:
+                try:
+                    _g = _ct.CDLL('libgssapi_krb5.so.2')
+                    _m = _ct.c_uint32(0)
+                    _g.gss_krb5_ccache_name(_ct.byref(_m),
+                                            _cc.encode(), None)
+                except Exception:
+                    pass
             self.conn.sasl_interactive_bind_s(
                 '', auth_tokens, server_controls, client_controls)
 
