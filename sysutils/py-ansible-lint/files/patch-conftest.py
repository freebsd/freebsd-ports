--- conftest.py.orig	2023-05-09 16:16:59 UTC
+++ conftest.py
@@ -44,7 +44,7 @@ if not HAS_LIBYAML:
     # While presence of libyaml is not required for runtime, we keep this error
     # fatal here in order to be sure that we spot libyaml errors during testing.
     arch = platform.machine()
-    if arch not in ("arm64", "x86_64"):
+    if arch not in ("arm64", "amd64"):
         warnings.warn(
             f"This architecture ({arch}) is not supported by libyaml, performance will be degraded.",
             category=pytest.PytestWarning,
