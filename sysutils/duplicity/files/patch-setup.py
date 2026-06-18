--- setup.py.orig	2026-06-17 21:18:32 UTC
+++ setup.py
@@ -108,18 +108,6 @@ def get_data_files():
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
