--- python/samba/provision/sambadns.py.orig	2026-01-20 15:42:54 UTC
+++ python/samba/provision/sambadns.py
@@ -21,6 +21,7 @@ import os
 """DNS-related provisioning"""
 
 import os
+import re
 import uuid
 import shutil
 import time
@@ -1008,53 +1009,37 @@ def create_named_conf(paths, realm, dnsdomain, dns_bac
                                      stderr=subprocess.STDOUT,
                                      cwd='.').communicate()[0]
         bind_info = get_string(bind_info)
-        bind9_8 = '#'
-        bind9_9 = '#'
-        bind9_10 = '#'
-        bind9_11 = '#'
-        bind9_12 = '#'
-        bind9_14 = '#'
-        bind9_16 = '#'
-        bind9_18 = '#'
-        if bind_info.upper().find('BIND 9.8') != -1:
-            bind9_8 = ''
-        elif bind_info.upper().find('BIND 9.9') != -1:
-            bind9_9 = ''
-        elif bind_info.upper().find('BIND 9.10') != -1:
-            bind9_10 = ''
-        elif bind_info.upper().find('BIND 9.11') != -1:
-            bind9_11 = ''
-        elif bind_info.upper().find('BIND 9.12') != -1:
-            bind9_12 = ''
-        elif bind_info.upper().find('BIND 9.14') != -1:
-            bind9_14 = ''
-        elif bind_info.upper().find('BIND 9.16') != -1:
-            bind9_16 = ''
-        elif bind_info.upper().find('BIND 9.18') != -1 \
-          or bind_info.upper().find('BIND 9.20') != -1:
-            bind9_18 = ''
-        elif bind_info.upper().find('BIND 9.7') != -1:
-            raise ProvisioningError("DLZ option incompatible with BIND 9.7.")
-        elif bind_info.upper().find('BIND_9.13') != -1:
-            raise ProvisioningError("Only stable/esv releases of BIND are supported.")
-        elif bind_info.upper().find('BIND_9.15') != -1:
-            raise ProvisioningError("Only stable/esv releases of BIND are supported.")
-        elif bind_info.upper().find('BIND_9.17') != -1:
-            raise ProvisioningError("Only stable/esv releases of BIND are supported.")
+        bind9_release = re.search('BIND (9)\.(\d+)\.', bind_info, re.I)
+        if bind9_release:
+            bind9_disabled = ''
+            bind9_version = bind9_release.group(0) + "x"
+            bind9_version_major = int(bind9_release.group(1))
+            bind9_version_minor = int(bind9_release.group(2))
+            if bind9_version_minor == 7:
+                raise ProvisioningError("DLZ option incompatible with BIND 9.7.")
+            elif bind9_version_minor == 8:
+                bind9_dlz_version = "9"
+            elif bind9_version_minor in [13, 15, 17]:
+                raise ProvisioningError("Only stable/esv releases of BIND are supported.")
+            else:
+                bind9_dlz_version = "%d_%d" % (bind9_version_major, bind9_version_minor)
         else:
+            bind9_disabled = '# '
+            bind9_version = "BIND z.y.x"
+            bind9_dlz_version = "z_y"
             logger.warning("BIND version unknown, please modify %s manually." % paths.namedconf)
+
+        bind9_dlz = (
+            '    # For %s\n'
+            '    %sdatabase "dlopen %s/bind9/dlz_bind%s.so";'
+        ) % (
+            bind9_version, bind9_disabled, samba.param.modules_dir(), bind9_dlz_version
+        )
         setup_file(setup_path("named.conf.dlz"), paths.namedconf, {
                     "NAMED_CONF": paths.namedconf,
                     "MODULESDIR": samba.param.modules_dir(),
-                    "BIND9_8": bind9_8,
-                    "BIND9_9": bind9_9,
-                    "BIND9_10": bind9_10,
-                    "BIND9_11": bind9_11,
-                    "BIND9_12": bind9_12,
-                    "BIND9_14": bind9_14,
-                    "BIND9_16": bind9_16,
-                    "BIND9_18": bind9_18
-                    })
+                    "BIND9_DLZ": bind9_dlz
+                 })
 
 
 def create_named_txt(path, realm, dnsdomain, dnsname, binddns_dir,
