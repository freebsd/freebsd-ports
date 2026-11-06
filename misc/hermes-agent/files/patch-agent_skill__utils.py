--- agent/skill_utils.py.orig	2026-11-06 16:56:46 UTC
+++ agent/skill_utils.py
@@ -101,7 +101,8 @@ def skill_matches_platform_list(platforms: Any) -> boo
     for platform in platforms:
         normalized = str(platform).lower().strip()
         mapped = PLATFORM_MAP.get(normalized, normalized)
-        if current.startswith(mapped):
+        # FreeBSD is POSIX-compatible: accept linux-tagged skills too.
+        if current.startswith(mapped) or (sys.platform.startswith("freebsd") and mapped == "linux"):
             return True
     return False
 
