--- src/greaseweazle/tools/util.py.orig	2025-12-17 09:54:59 UTC
+++ src/greaseweazle/tools/util.py
@@ -356,6 +356,9 @@
 def score_port(x, old_port=None):
     score = 0
+    # pyserial's FreeBSD DevInfo may lack USB attributes on non-USB ports
+    if not hasattr(x, 'manufacturer'):
+        return score
     if x.manufacturer == "Keir Fraser" and x.product == "Greaseweazle":
         score = 20
     elif x.vid == 0x1209 and x.pid == 0x4d69:
