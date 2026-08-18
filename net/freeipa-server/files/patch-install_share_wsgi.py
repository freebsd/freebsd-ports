--- install/share/wsgi.py.orig	2025-01-15 09:52:51 UTC
+++ install/share/wsgi.py
@@ -23,6 +23,15 @@ WSGI application for IPA server.
 """
 WSGI application for IPA server.
 """
+# FreeBSD: FreeIPA does not use DNS-over-QUIC.  Disable dnspython's optional
+# "doq" feature before ipaserver.wsgi imports dns.resolver, otherwise dnspython
+# pulls in aioquic -> pyOpenSSL inside httpd/mod_wsgi, where that import fails
+# ("import of OpenSSL.SSL halted; None in sys.modules") and the /ipa web API
+# returns HTTP 503, breaking ipa-client enrolment during ipa-server-install.
+import dns._features
+
+dns._features.force("doq", False)
+
 from ipaserver.wsgi import create_application
 
 application = create_application()
