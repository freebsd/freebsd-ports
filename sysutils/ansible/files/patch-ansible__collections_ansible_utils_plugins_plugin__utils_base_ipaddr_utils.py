--- ansible_collections/ansible/utils/plugins/plugin_utils/base/ipaddr_utils.py.orig	2023-09-07 02:17:47.000000000 -0700
+++ ansible_collections/ansible/utils/plugins/plugin_utils/base/ipaddr_utils.py	2024-05-15 08:23:34.190190000 -0700
@@ -289,7 +289,7 @@
 
 
 def _private_query(v, value):
-    if v.is_private():
+    if not v.ip.is_global():
         return value
 
 
@@ -298,7 +298,7 @@
     if all(
         [
             v_ip.is_unicast(),
-            not v_ip.is_private(),
+            v_ip.is_global(),
             not v_ip.is_loopback(),
             not v_ip.is_netmask(),
             not v_ip.is_hostmask(),
