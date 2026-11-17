--- hermes_cli/config_defaults.py.orig	2026-11-16 19:28:45 UTC
+++ hermes_cli/config_defaults.py
@@ -4,6 +4,8 @@ docs of config.yaml.
 docs of config.yaml.
 """
 
+import sys
+
 from hermes_cli.config_defaults_auxiliary import _aux
 from hermes_cli.config_defaults_voice import VOICE_DEFAULTS
 
@@ -1738,8 +1740,10 @@ DEFAULT_CONFIG = {
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
