--- src/common/gen/Templator.py.orig	2026-11-20 19:02:21 UTC
+++ src/common/gen/Templator.py
@@ -9,7 +9,7 @@ import multiprocessing as mp
 from glob import glob
 from math import ceil
 import multiprocessing as mp
-from os.path import basename, join, sep
+from os.path import basename, isfile, join, sep
 from pathlib import Path
 from random import choice
 from ssl import PROTOCOL_TLS_SERVER, SSLContext
@@ -439,6 +439,7 @@ class Templator:
             "import": import_module,
             "resolve_ssl_ecdh_curve": resolve_ssl_ecdh_curve,
             "normalize_memory_size": Templator._normalize_memory_size,
+            "has_modsecurity": isfile("/usr/local/nginx/modules/ngx_http_modsecurity_module.so"),
         }
 
         self._server_env_cache: Dict[str, Environment] = {}
@@ -777,6 +778,8 @@ class Templator:
         template_vars = self._base_template_vars.copy()
         template_vars["all"] = full_config
         template_vars.update(config)
+        if "NGINX_PREFIX" not in config:
+            template_vars["NGINX_PREFIX"] = f"{self._target}/"
         # Derived values cannot be shadowed by a setting.
         template_vars["global_config"] = self._global_only_full_config
         template_vars["STREAM_REUSEPORT_PORTS"] = self._stream_reuseport_ports.get(server, set())
