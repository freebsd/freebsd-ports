--- agent/skill_utils.py.orig	2026-09-24 10:08:47 UTC
+++ agent/skill_utils.py
@@ -135,7 +135,12 @@ def skill_matches_platform_list(platforms: Any) -> boo
         mapped = PLATFORM_MAP.get(normalized, normalized)
         # Termux is a Linux userland on Android: accept linux-tagged skills
         # whether sys.platform is "linux" (pre-3.13) or "android" (3.13+).
-        if sys.platform.startswith(mapped) or (running_in_termux and mapped in ("linux", "termux", "android")):
+        # FreeBSD is POSIX-compatible: accept linux-tagged skills too.
+        if (
+            sys.platform.startswith(mapped)
+            or (running_in_termux and mapped in ("linux", "termux", "android"))
+            or (sys.platform.startswith("freebsd") and mapped == "linux")
+        ):
             return True
     return False
 
