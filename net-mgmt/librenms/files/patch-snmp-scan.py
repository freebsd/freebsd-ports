--- snmp-scan.py.orig	2023-10-04 12:28:53 UTC
+++ snmp-scan.py
@@ -133,8 +133,7 @@ def scan_host(scan_ip):
                 return Result(scan_ip, hostname, Outcome.NODNS, "DNS not Resolved")
 
             arguments = [
-                "/usr/bin/env",
-                "lnms",
+                "/usr/local/bin/lnms",
                 "device:add",
                 "-g",
                 POLLER_GROUP,
@@ -259,7 +258,7 @@ Example: 192.168.0.1/32 will be treated as a single ho
     chdir(install_dir)
     try:
         CONFIG = json.loads(
-            check_output(["/usr/bin/env", "php", "config_to_json.php"]).decode()
+            check_output(["/usr/local/bin/php", "config_to_json.php"]).decode()
         )
     except CalledProcessError as e:
         parser.error(
