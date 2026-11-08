--- setup.py.orig	2026-10-19 18:32:48 UTC
+++ setup.py
@@ -112,22 +112,6 @@ def get_data_files():
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
-                "README-ARCH.md",
-                "README-INSTALL.md",
-                "README-LOG.md",
-                "README-RELEASE.md",
-                "README-REPO.md",
-                "README-SNAP.md",
-                "README-TESTING.md",
-            ],
-        ),
     ]
 
     # short circuit fot READTHEDOCS
