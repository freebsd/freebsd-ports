--- agent/skill_utils.py.orig	2026-08-31 19:29:27 UTC
+++ agent/skill_utils.py
@@ -237,6 +237,9 @@ def skill_matches_platform_list(platforms: Any) -> boo
         mapped = PLATFORM_MAP.get(normalized, normalized)
         if current.startswith(mapped):
             return True
+        # FreeBSD is POSIX-compatible; accept linux-tagged skills.
+        if current.startswith("freebsd") and mapped == "linux":
+            return True
         # Termux runs a Linux userland on Android. Accept linux-tagged
         # skills regardless of whether sys.platform is "linux" (pre-3.13
         # Termux) or "android" (Python 3.13+ Termux, and any other
