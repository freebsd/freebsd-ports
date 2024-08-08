--- setup.py.orig	2024-08-05 18:50:31 UTC
+++ setup.py
@@ -115,8 +115,6 @@ REQUIRED_PKGS = [
     # Backend and serialization.
     # Minimum 15.0.0 to be able to cast dictionary types to their underlying types
     "pyarrow>=15.0.0",
-    # As long as we allow pyarrow < 14.0.1, to fix vulnerability CVE-2023-47248
-    "pyarrow-hotfix",
     # For smart caching dataset processing
     "dill>=0.3.0,<0.3.9",  # tmp pin until dill has official support for determinism see https://github.com/uqfoundation/dill/issues/19
     # For performance gains with apache arrow
