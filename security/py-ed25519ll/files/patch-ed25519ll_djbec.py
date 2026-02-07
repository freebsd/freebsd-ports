--- ed25519ll/djbec.py.orig	2017-12-25 20:10:10 UTC
+++ ed25519ll/djbec.py
@@ -36,10 +36,8 @@ def H(m):
     return hashlib.sha512(m).digest()
 
 def expmod(b, e, m):
-    if e == 0: return 1
-    t = expmod(b, e // 2, m) ** 2 % m
-    if e & 1: t = (t * b) % m
-    return t
+    # the built-in pow is much faster
+    return pow(b,e,m)
 
 # Can probably get some extra speedup here by replacing this with
 # an extended-euclidean, but performance seems OK without that
