--- setup.py.orig	2025-11-03 12:04:09 UTC
+++ setup.py
@@ -112,18 +112,6 @@ def get_data_files():
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
