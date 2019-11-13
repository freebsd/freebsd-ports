Obtained from:	https://github.com/sdgathman/pyspf/commit/4744deeec4a2c10987aae72989d7137156ed4151

--- spf.py.orig
+++ spf.py
@@ -91,7 +91,7 @@
         print('ipaddr module required: http://code.google.com/p/ipaddr-py/')
 
 
-def DNSLookup_pydns(name, qtype, tcpfallback=True, timeout=30):
+def DNSLookup_pydns(name, qtype, strict=True, timeout=20):
 
     try:
         req = DNS.DnsRequest(name, qtype=qtype, timeout=timeout)
