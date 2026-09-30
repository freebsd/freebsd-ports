--- hermes_cli/config_defaults.py.orig	2026-09-24 10:08:47 UTC
+++ hermes_cli/config_defaults.py
@@ -4,7 +4,9 @@ docs of config.yaml.
 docs of config.yaml.
 """
 
+import sys
 
+
 def _aux(timeout, *, reasoning_effort=True, **extra):
     """Standard auxiliary-task model block (see DEFAULT_CONFIG["auxiliary"]).
 
@@ -1761,8 +1763,10 @@ DEFAULT_CONFIG = {
         "acked_advisories": [],
         # Lazy-install opt-in backend packages from PyPI when a backend that needs them is first
         # enabled (e.g. `elevenlabs`). False = require explicit pip install for everything beyond
-        # the base set (restricted/audited/air-gapped environments).
-        "allow_lazy_installs": True,
+        # the base set (restricted/audited/air-gapped environments). Defaults to False on FreeBSD:
+        # the package manager owns the site-packages tree, and runtime pip writes there create
+        # pkg-invisible files.
+        "allow_lazy_installs": not sys.platform.startswith("freebsd"),
     },
 
     "cron": {
