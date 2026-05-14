--- src/common/gen/Templator.py.orig	2026-05-28 20:12:40 UTC
+++ src/common/gen/Templator.py
@@ -650,6 +650,7 @@ class Templator:
         template_vars = self._base_template_vars.copy()
         template_vars["all"] = full_config
         template_vars.update(config)
+        template_vars["NGINX_PREFIX"] = f"{self._target}/"
 
         for template in templates:
             name = basename(template) if any(template.endswith(root_conf) for root_conf in self._global_templates) else None
