Backport from:	https://github.com/elastic/elasticsearch-py/commit/4c531c5cdbd5ba8b59be16c2fa15d5cf81d0a92f

--- elasticsearch/connection/http_urllib3.py.orig	2019-05-28 17:59:13 UTC
+++ elasticsearch/connection/http_urllib3.py
@@ -170,6 +170,7 @@ class Urllib3HttpConnection(Connection):
                     }
                 )
             else:
+                kw["cert_reqs"] = "CERT_NONE"
                 warnings.warn(
                     "Connecting to %s using SSL with verify_certs=False is insecure."
                     % host
