--- hermes_cli/config_defaults.py.orig	2026-10-23 02:24:27 UTC
+++ hermes_cli/config_defaults.py
@@ -4,7 +4,9 @@ Pure-data leaf module — must not import from hermes_cl
 docs of config.yaml.
 """
 
+import sys
 
+
 #: Image every container terminal backend (docker/modal/daytona, the singularity plugin) uses unless the
 #: user pins one. LEGACY_SANDBOX_IMAGES are the plain defaults that preceded the desktop stack
 #: (the 3.14 pin shipped between the two without a migration); a saved config still holding one
@@ -1807,8 +1809,10 @@ DEFAULT_CONFIG = {
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
