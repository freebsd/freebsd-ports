--- src/apolicy/config.py.orig	2008-11-24 07:53:32 UTC
+++ src/apolicy/config.py
@@ -22,7 +22,7 @@
 import pwd
 from ConfigParser import ConfigParser
 
-config_path = "/etc/apolicy/main.conf"
+config_path = "/usr/local/etc/apolicy/main.conf"
 
 if "APOLICY_CONFIG_PATH" in os.environ:
     config_path = os.environ["APOLICY_CONFIG_PATH"]
@@ -42,7 +42,7 @@
     config.set("main", "timeout", "5")
 
 if not config.has_option("main", "policy_path"):
-    config.set("main", "policy_path", "/etc/apolicy/policy.conf")
+    config.set("main", "policy_path", "/usr/local/etc/apolicy/policy.conf")
 
 user = pwd.getpwnam(config.get("main", "user"))
 config.set("main", "uid", str(user[2]))
