--- src/ui/utils/gunicorn.conf.py.orig	2026-05-28 20:12:40 UTC
+++ src/ui/utils/gunicorn.conf.py
@@ -11,7 +11,7 @@ from traceback import format_exc
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
-chdir = join(sep, "usr", "share", "bunkerweb", "ui")
+chdir = join(sep, "usr", "local", "share", "bunkerweb", "ui")
 umask = 0x027
 pidfile = PID_FILE.as_posix()
 control_socket_disable = True
@@ -108,7 +108,7 @@ forwarded_allow_ips = FORWARDED_ALLOW_IPS
     "X-FORWARDED-SSL": "on",
 }
 forwarded_allow_ips = FORWARDED_ALLOW_IPS
-pythonpath = join(sep, "usr", "share", "bunkerweb", "deps", "python") + "," + join(sep, "usr", "share", "bunkerweb", "ui")
+pythonpath = join(sep, "usr", "local", "share", "bunkerweb", "deps", "python") + "," + join(sep, "usr", "local", "share", "bunkerweb", "ui")
 proxy_allow_ips = PROXY_ALLOW_IPS
 casefold_http_method = True
 workers = MAX_WORKERS
@@ -128,7 +128,7 @@ if DEBUG:
     reload = True
     reload_extra_files = [
         file.as_posix()
-        for file in Path(sep, "usr", "share", "bunkerweb", "ui", "app").rglob("*")
+        for file in Path(sep, "usr", "local", "share", "bunkerweb", "ui", "app").rglob("*")
         if "__pycache__" not in file.parts and "static" not in file.parts
     ]
 
