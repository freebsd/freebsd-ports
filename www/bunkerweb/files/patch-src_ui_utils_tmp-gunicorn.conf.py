--- src/ui/utils/tmp-gunicorn.conf.py.orig	2026-05-28 20:12:40 UTC
+++ src/ui/utils/tmp-gunicorn.conf.py
@@ -3,7 +3,7 @@ from sys import path as sys_path
 from pathlib import Path
 from sys import path as sys_path
 
-for deps_path in [join(sep, "usr", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("utils",), ("api",), ("db",))]:
+for deps_path in [join(sep, "usr", "local", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("utils",), ("api",), ("db",))]:
     if deps_path not in sys_path:
         sys_path.append(deps_path)
 
@@ -54,7 +54,7 @@ daemon = bool(DEBUG)
 limit_request_field_size = 0
 reuse_port = True
 daemon = bool(DEBUG)
-chdir = join(sep, "usr", "share", "bunkerweb", "ui")
+chdir = join(sep, "usr", "local", "share", "bunkerweb", "ui")
 umask = 0x027
 pidfile = PID_FILE.as_posix()
 control_socket_disable = True
@@ -64,7 +64,7 @@ forwarded_allow_ips = FORWARDED_ALLOW_IPS
 tmp_upload_dir = TMP_UI_DIR.as_posix()
 secure_scheme_headers = {}
 forwarded_allow_ips = FORWARDED_ALLOW_IPS
-pythonpath = join(sep, "usr", "share", "bunkerweb", "deps", "python") + "," + join(sep, "usr", "share", "bunkerweb", "ui")
+pythonpath = join(sep, "usr", "local", "share", "bunkerweb", "deps", "python") + "," + join(sep, "usr", "local", "share", "bunkerweb", "ui")
 proxy_allow_ips = PROXY_ALLOW_IPS
 casefold_http_method = True
 workers = 1
@@ -81,7 +81,7 @@ if DEBUG:
     reload = True
     reload_extra_files = [
         file.as_posix()
-        for file in Path(sep, "usr", "share", "bunkerweb", "ui", "app").rglob("*")
+        for file in Path(sep, "usr", "local", "share", "bunkerweb", "ui", "app").rglob("*")
         if "__pycache__" not in file.parts and "static" not in file.parts
     ]
 
