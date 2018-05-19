--- Milter/dns.py.orig	2016-12-13 19:17:34 UTC
+++ Milter/dns.py
@@ -26,8 +26,8 @@ def DNSLookup(name, qtype):
         # A RR as dotted quad.  For consistency, this driver should
         # return both as binary string.
         return [((a['name'], a['typename']), a['data']) for a in resp.answers]
-    except IOError, x:
-        raise DNSError, str(x)
+    except IOError as x:
+        raise DNSError(str(x))
 
 class Session(object):
   """A Session object has a simple cache with no TTL that is valid
