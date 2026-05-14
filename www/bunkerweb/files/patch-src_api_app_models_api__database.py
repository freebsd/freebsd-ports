--- src/api/app/models/api_database.py.orig	2026-05-10 11:25:04 UTC
+++ src/api/app/models/api_database.py
@@ -6,7 +6,7 @@ from typing import Optional, Union
 from typing import Optional, Union
 
 
-for deps_path in [join(sep, "usr", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("utils",), ("api",), ("db",))]:
+for deps_path in [join(sep, "usr", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("common", "utils"), ("api",), ("common", "db"))]:
     if deps_path not in sys_path:
         sys_path.append(deps_path)
 
