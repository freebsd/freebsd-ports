--- setup.py.orig	2023-12-25 16:22:33 UTC
+++ setup.py
@@ -87,18 +87,6 @@ def get_data_files():
                 "bin/duplicity.1",
             ],
         ),
-        (
-            f"share/doc/duplicity-{Version}",
-            [
-                "CHANGELOG.md",
-                "CONTRIBUTING.md",
-                "COPYING",
-                "README.md",
-                "README-LOG.md",
-                "README-REPO.md",
-                "README-TESTING.md",
-            ],
-        ),
     ]
 
     # short circuit fot READTHEDOCS
