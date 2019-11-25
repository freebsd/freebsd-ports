Fix verify_certs=False behavior for urllib >= 1.25. Backported from the 7.x branch:

https://github.com/elastic/elasticsearch-py/commit/4c531c5cdbd5ba8b59be16c2fa15d5cf81d0a92f

--- elasticsearch/connection/http_urllib3.py.orig	2018-01-16 15:26:23 UTC
+++ elasticsearch/connection/http_urllib3.py
@@ -84,6 +84,7 @@ class Urllib3HttpConnection(Connection):
                     'cert_reqs': 'CERT_REQUIRED',
                 })
             else:
+                kw["cert_reqs"] = "CERT_NONE"
                 warnings.warn(
                     'Connecting to %s using SSL with verify_certs=False is insecure.' % host)
                 kw.update({
