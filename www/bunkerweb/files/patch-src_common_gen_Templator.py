--- src/common/gen/Templator.py.orig	2026-09-21 08:05:39 UTC
+++ src/common/gen/Templator.py
@@ -9,7 +9,7 @@
 from glob import glob
 from math import ceil
 import multiprocessing as mp
-from os.path import basename, join, sep
+from os.path import basename, isfile, join, sep
 from pathlib import Path
 from random import choice
 from ssl import PROTOCOL_TLS_SERVER, SSLContext
@@ -441,6 +441,7 @@
             "import": import_module,
             "resolve_ssl_ecdh_curve": resolve_ssl_ecdh_curve,
             "normalize_memory_size": Templator._normalize_memory_size,
+            "has_modsecurity": isfile("/usr/local/nginx/modules/ngx_http_modsecurity_module.so"),
         }
 
         self._server_env_cache: Dict[str, Environment] = {}
@@ -721,6 +722,7 @@
         template_vars = self._base_template_vars.copy()
         template_vars["all"] = full_config
         template_vars.update(config)
+        template_vars["NGINX_PREFIX"] = f"{self._target}/"
 
         for template in templates:
             name = basename(template) if any(template.endswith(root_conf) for root_conf in self._global_templates) else None
