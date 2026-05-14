--- src/api/utils/gunicorn.conf.py.orig	2026-05-28 20:12:40 UTC
+++ src/api/utils/gunicorn.conf.py
@@ -10,7 +10,7 @@ from traceback import format_exc
 from time import sleep
 from traceback import format_exc
 
-for deps_path in [join(sep, "usr", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("utils",), ("api",), ("db",))]:
+for deps_path in [join(sep, "usr", "local", "share", "bunkerweb", *paths) for paths in (("deps", "python"), ("utils",), ("api",), ("db",))]:
     if deps_path not in sys_path:
         sys_path.append(deps_path)
 
@@ -94,7 +94,7 @@ daemon = False
 limit_request_field_size = 0
 reuse_port = False
 daemon = False
-chdir = join(sep, "usr", "share", "bunkerweb", "api")
+chdir = join(sep, "usr", "local", "share", "bunkerweb", "api")
 umask = 0x027
 pidfile = PID_FILE.as_posix()
 control_socket_disable = True
@@ -108,7 +108,7 @@ forwarded_allow_ips = FORWARDED_ALLOW_IPS
     "X-FORWARDED-SSL": "on",
 }
 forwarded_allow_ips = FORWARDED_ALLOW_IPS
-pythonpath = join(sep, "usr", "share", "bunkerweb", "deps", "python") + "," + join(sep, "usr", "share", "bunkerweb", "api")
+pythonpath = join(sep, "usr", "local", "share", "bunkerweb", "deps", "python") + "," + join(sep, "usr", "local", "share", "bunkerweb", "api")
 proxy_allow_ips = PROXY_ALLOW_IPS
 casefold_http_method = True
 workers = MAX_WORKERS
@@ -128,7 +128,7 @@ if DEBUG:
     reload = True
     reload_extra_files = [
         file.as_posix()
-        for file in Path(sep, "usr", "share", "bunkerweb", "api", "app").rglob("*")
+        for file in Path(sep, "usr", "local", "share", "bunkerweb", "api", "app").rglob("*")
         if "__pycache__" not in file.parts and "static" not in file.parts
     ]
 
