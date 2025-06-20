--- setup.py.orig	2025-06-19 16:01:57 UTC
+++ setup.py
@@ -113,18 +113,6 @@ def get_data_files():
                 "man/duplicity.1",
             ],
         ),
-        (
-            f"share/doc/duplicity-{Version}",
-            [
-                "CHANGELOG.md",
-                "AUTHORS.md",
-                "COPYING",
-                "README.md",
-                "README-LOG.md",
-                "README-REPO.md",
-                "README-TESTING.md",
-            ],
-        ),
     ]
 
     # short circuit fot READTHEDOCS
