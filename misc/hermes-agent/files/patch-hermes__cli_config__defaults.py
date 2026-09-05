--- hermes_cli/config_defaults.py.orig	2026-08-31 19:29:27 UTC
+++ hermes_cli/config_defaults.py
@@ -4,6 +4,8 @@ verbatim from hermes_cli/config.py. Must not import fr
 verbatim from hermes_cli/config.py. Must not import from hermes_cli.config.
 """
 
+import sys
+
 DEFAULT_CONFIG = {
     "model": "",
     "providers": {},
@@ -2700,8 +2702,10 @@ DEFAULT_CONFIG = {
         # their TTS provider). Set to false to require explicit
         # ``pip install`` for everything beyond the base set — appropriate
         # for restricted networks, audited environments, or air-gapped
-        # systems where any runtime install is unacceptable.
-        "allow_lazy_installs": True,
+        # systems where any runtime install is unacceptable.  Defaults to
+        # False on FreeBSD: the package manager owns the site-packages tree,
+        # and runtime pip writes there create pkg-invisible files.
+        "allow_lazy_installs": not sys.platform.startswith("freebsd"),
     },
 
     "cron": {
