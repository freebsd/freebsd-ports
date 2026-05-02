--- netron/server.py.orig	2026-05-02 17:42:00 UTC
+++ netron/server.py
@@ -207,8 +207,8 @@ def _make_port(address):
     if address[1] is None or address[1] == 0:
         ports = []
         if address[1] != 0:
-            ports.append(8080)
-            ports.append(8081)
+            ports.append(18080)
+            ports.append(18081)
             rnd = random.Random()
             for _ in range(4):
                 port = rnd.randrange(15000, 25000)
