--- agent/skill_utils.py.orig	2026-10-26 16:08:51 UTC
+++ agent/skill_utils.py
@@ -97,7 +97,8 @@
     for platform in platforms:
         normalized = str(platform).lower().strip()
         mapped = PLATFORM_MAP.get(normalized, normalized)
-        if current.startswith(mapped):
+        # FreeBSD is POSIX-compatible: accept linux-tagged skills too.
+        if current.startswith(mapped) or (sys.platform.startswith("freebsd") and mapped == "linux"):
             return True
     return False
 
