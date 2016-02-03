--- salt/state.py.orig	2016-02-03 17:25:12 UTC
+++ salt/state.py
@@ -190,7 +190,7 @@ def find_name(name, state, high):
                         if len(arg) != 1:
                             continue
                         if arg[next(iter(arg))] == name:
-                            ext_id.append((name, state))
+                            ext_id.append((nid, state))
     return ext_id
 
 
