--- python/samba/provision/sambadns.py.orig	2018-01-17 09:08:39 UTC
+++ python/samba/provision/sambadns.py
@@ -937,6 +937,7 @@ def create_named_conf(paths, realm, dnsd
         bind9_9 = '#'
         bind9_10 = '#'
         bind9_11 = '#'
+        bind9_12 = '#'
         if bind_info.upper().find('BIND 9.8') != -1:
             bind9_8 = ''
         elif bind_info.upper().find('BIND 9.9') != -1:
@@ -945,6 +946,8 @@ def create_named_conf(paths, realm, dnsd
             bind9_10 = ''
         elif bind_info.upper().find('BIND 9.11') != -1:
             bind9_11 = ''
+        elif bind_info.upper().find('BIND 9.12') != -1:
+            bind9_12 = ''
         elif bind_info.upper().find('BIND 9.7') != -1:
             raise ProvisioningError("DLZ option incompatible with BIND 9.7.")
         else:
@@ -955,7 +958,8 @@ def create_named_conf(paths, realm, dnsd
                     "BIND9_8" : bind9_8,
                     "BIND9_9" : bind9_9,
                     "BIND9_10" : bind9_10,
-                    "BIND9_11" : bind9_11
+                    "BIND9_11" : bind9_11,
+                    "BIND9_12" : bind9_12
                     })
 
 
