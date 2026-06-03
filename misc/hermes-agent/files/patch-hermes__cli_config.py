--- hermes_cli/config.py.orig	2026-05-16 09:59:15 UTC
+++ hermes_cli/config.py	2026-05-19 11:15:59.334355000 +0200
@@ -1421,7 +1421,15 @@
         # ``pip install`` for everything beyond the base set — appropriate
         # for restricted networks, audited environments, or air-gapped
         # systems where any runtime install is unacceptable.
-        "allow_lazy_installs": True,
+        # FreeBSD: default disabled.  This port runs hermes against
+        # the system Python, not a venv, so ``pip install`` would
+        # either fail outright (PEP 668 / EXTERNALLY-MANAGED blocks
+        # both ${PREFIX} and the --user fallback) or, if forced,
+        # write into ${PREFIX} outside pkg's manifest.  Either way
+        # the feature is unusable here; turn it off so users get a
+        # clean "install the py-* port" message instead of a pip
+        # traceback.
+        "allow_lazy_installs": False,
     },
 
     "cron": {
