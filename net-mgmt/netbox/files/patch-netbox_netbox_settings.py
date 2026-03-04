Remove check for Python < 3.12

--- netbox/netbox/settings.py.orig	2026-03-03 21:01:30 UTC
+++ netbox/netbox/settings.py
@@ -33,12 +33,6 @@ BASE_DIR = os.path.dirname(os.path.dirname(os.path.abs
 # Set the base directory two levels up
 BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
 
-# Validate the Python version
-if sys.version_info < (3, 12):  # noqa: UP036
-    raise RuntimeError(
-        f"NetBox requires Python 3.12 or later. (Currently installed: Python {platform.python_version()})"
-    )
-
 #
 # Configuration import
 #
