--- subsystem/lib-python/src/nav/ip.py.orig	Sat Nov 20 18:35:46 2004
+++ subsystem/lib-python/src/nav/ip.py	Sat Nov 20 18:35:57 2004
@@ -106,7 +106,7 @@
         address = address.strip()
         matches = _cidrPattern.match(address)
 
-        fullmask = 0xFFFFFFFF
+        fullmask = 0xFFFFFFFFL
 
         if matches:
             g = matches.groups()
