--- hermes_cli/main.py.orig	2026-08-03 16:57:23 UTC
+++ hermes_cli/main.py
@@ -11112,6 +11112,16 @@ def cmd_skills(args):
 
 
 def cmd_skills(args):
+    # Seed ~/.hermes/skills/ from the bundled library before any skills
+    # subcommand runs.  Without this, a fresh install's `hermes skills list`
+    # reports zero skills — the sync only fires from cmd_chat / cmd_gateway /
+    # cmd_dashboard, so a user who runs `hermes skills` first sees an empty
+    # catalog and (reasonably) assumes something is broken.  On FreeBSD in
+    # particular the port ships bundled skills under DATADIR and exposes the
+    # path via HERMES_BUNDLED_SKILLS; without this sync call, the catalog stays
+    # empty forever until the user happens to run one of the other entrypoints.
+    _sync_bundled_skills_quietly()
+
     # Route 'config' action to skills_config module
     if getattr(args, "skills_action", None) == "config":
         _require_tty("skills config")
