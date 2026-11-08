Description: Load device profiles with importlib instead of imp, removed in
  Python 3.12.
Issue ID: https://github.com/napalm-automation/napalm-logs/issues/393
Changeset: https://github.com/napalm-automation/napalm-logs/pull/394 (open,
  not ours)
TODO: Drop when a release includes PR #394.

--- napalm_logs/base.py.orig	2026-10-12 02:31:51 UTC
+++ napalm_logs/base.py
@@ -7,7 +7,7 @@ import re
 # Import std lib
 import os
 import re
-import imp
+import importlib.util
 import sys
 import time
 import yaml
@@ -346,8 +346,10 @@ class NapalmLogs:
                             raise IOError(yamlexc)
                 elif file_extension == "py":
                     log.debug("Lazy loading Python module %s", file_)
-                    mod_fp, mod_file, mod_data = imp.find_module(file_name, [os_dir])
-                    mod = imp.load_module(file_name, mod_fp, mod_file, mod_data)
+                    spec = importlib.util.spec_from_file_location(file_name, filepath)
+                    mod = importlib.util.module_from_spec(spec)
+                    sys.modules[file_name] = mod
+                    spec.loader.exec_module(mod)
                     if file_name in CONFIG.OS_INIT_FILENAMES:
                         # Init file defined as Python module
                         log.debug("%s seems to be a Python profiler", filepath)
