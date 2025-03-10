--- searx/network/client.py.orig	2025-02-04 00:34:42 UTC
+++ searx/network/client.py
@@ -14,8 +14,8 @@ from searx import logger
 import uvloop
 
 from searx import logger
+from urllib3.util.ssl_ import DEFAULT_CIPHERS
 
-
 uvloop.install()
 
 
@@ -41,7 +41,7 @@ def shuffle_ciphers(ssl_context):
        https://www.zenrows.com/blog/what-is-tls-fingerprint#how-to-bypass-tls-fingerprinting
 
     """
-    c_list = httpx._config.DEFAULT_CIPHERS.split(':')  # pylint: disable=protected-access
+    c_list = DEFAULT_CIPHERS.split(':')  # pylint: disable=protected-access
     sc_list, c_list = c_list[:3], c_list[3:]
     random.shuffle(c_list)
     ssl_context.set_ciphers(":".join(sc_list + c_list))
@@ -50,7 +50,7 @@ def get_sslcontexts(proxy_url=None, cert=None, verify=
 def get_sslcontexts(proxy_url=None, cert=None, verify=True, trust_env=True, http2=False):
     key = (proxy_url, cert, verify, trust_env, http2)
     if key not in SSLCONTEXTS:
-        SSLCONTEXTS[key] = httpx.create_ssl_context(cert, verify, trust_env, http2)
+        SSLCONTEXTS[key] = httpx.create_ssl_context(verify, cert, trust_env)
     shuffle_ciphers(SSLCONTEXTS[key])
     return SSLCONTEXTS[key]
 
