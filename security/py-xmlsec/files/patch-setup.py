--- setup.py.orig	Fri Feb 13 08:55:47 2004
+++ setup.py	Fri Feb 13 08:57:30 2004
@@ -71,22 +71,22 @@
 
 # the crypto engine name : openssl, gnutls or nss
 xmlsec1_crypto = "openssl"
-if 'build' in sys.argv:
-    msg = '\nChoose a crypto engine :\n' \
-          '   1. OpenSSL\n' \
-          '   2. GnuTLS\n' \
-          '   3. NSS\n' \
-          'Your choice : '
-    reply = raw_input(msg)
-    choice = None
-    if reply:
-        choice = reply[0]
-    if choice == '1':
-        xmlsec1_crypto = "openssl"
-    elif choice == '2':
-        xmlsec1_crypto = "gnutls"
-    elif choice == '3':
-        xmlsec1_crypto = "nss"
+#if 'build' in sys.argv:
+#    msg = '\nChoose a crypto engine :\n' \
+#          '   1. OpenSSL\n' \
+#          '   2. GnuTLS\n' \
+#          '   3. NSS\n' \
+#          'Your choice : '
+#    reply = raw_input(msg)
+#    choice = None
+#    if reply:
+#        choice = reply[0]
+#    if choice == '1':
+#        xmlsec1_crypto = "openssl"
+#    elif choice == '2':
+#        xmlsec1_crypto = "gnutls"
+#    elif choice == '3':
+#        xmlsec1_crypto = "nss"
 
 define_macros = []
 include_dirs  = []
