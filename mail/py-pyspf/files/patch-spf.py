--- spf.py.orig	2020-01-01 21:02:26 UTC
+++ spf.py
@@ -128,7 +128,7 @@ def DNSLookup_dnspython(name, qtype, tcpfallback=True,
     retVal = []
     try:
         # FIXME: how to disable TCP fallback in dnspython if not tcpfallback?
-        answers = dns.resolver.query(name, qtype, lifetime=timeout)
+        answers = dns.resolver.resolve(name, qtype, lifetime=timeout)
         for rdata in answers:
             if qtype == 'A' or qtype == 'AAAA':
                 retVal.append(((name, qtype), rdata.address))
