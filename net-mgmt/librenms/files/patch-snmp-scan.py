--- snmp-scan.py.orig	2024-09-30 20:13:09 UTC
+++ snmp-scan.py
@@ -265,7 +265,7 @@ Example: 192.168.0.1/32 will be treated as a single ho
     try:
         CONFIG = json.loads(
             check_output(
-                ["/usr/bin/env", "php", "lnms", "config:get", "--dump"]
+                ["%%LOCALBASE%%/bin/php", "config_to_json.php"]
             ).decode()
         )
     except CalledProcessError as e:
