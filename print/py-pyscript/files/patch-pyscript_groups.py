--- pyscript/groups.py.orig	2009-05-15 12:02:45.000000000 +0200
+++ pyscript/groups.py	2009-05-15 12:02:18.000000000 +0200
@@ -387,10 +387,10 @@
     assert a2 in ["n", "ne", "e", "se", "s", "sw", "w", "nw", "c"]
 
     # note the swap:
-    as = options.get('as', a2)
+    vas = options.get('as', a2)
     ae = options.get('ae', a1)
 
-    assert as in ["n", "ne", "e", "se", "s", "sw", "w", "nw", "c"]
+    assert vas in ["n", "ne", "e", "se", "s", "sw", "w", "nw", "c"]
     assert ae in ["n", "ne", "e", "se", "s", "sw", "w", "nw", "c"]
 
     # these two have to be present
@@ -424,14 +424,14 @@
 
         # place items at the edges
         # ---first object----
-        ov = getattr(items[0].bbox(), as)-p1
+        ov = getattr(items[0].bbox(), vas)-p1
 
         # how much we need to move by
         mv = -pv.U*ov*pv.U
         items[0].move(mv)
 
         space -= abs(( getattr(items[0].bbox(), a1)
-                         - getattr(items[0].bbox(), as) )*pv.U)
+                         - getattr(items[0].bbox(), vas) )*pv.U)
 
         # ---second object---
         ov = getattr(items[-1].bbox(), ae)-p2
