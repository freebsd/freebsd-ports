--- libcloud/httplib_ssl.py.orig	2015-02-07 21:51:40 UTC
+++ libcloud/httplib_ssl.py
@@ -23,7 +23,7 @@ import ssl
 import base64
 import warnings
 
-from backports.ssl_match_hostname import match_hostname, CertificateError
+from ssl import match_hostname, CertificateError
 
 import libcloud.security
 from libcloud.utils.py3 import b
