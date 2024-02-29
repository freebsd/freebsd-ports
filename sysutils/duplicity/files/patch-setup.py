--- setup.py.orig	2024-02-06 08:04:58 UTC
+++ setup.py
@@ -99,18 +99,6 @@ def get_data_files():
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
