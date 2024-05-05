--- setup.py.orig	2024-03-24 18:42:39 UTC
+++ setup.py
@@ -36,7 +36,6 @@ class build_ext(_build_ext):
             "binding": True,
             "cdivision": True,
             "language_level": 2,
-            "legacy_implicit_noexcept": True,
             "c_api_binop_methods": True,
         }
 
