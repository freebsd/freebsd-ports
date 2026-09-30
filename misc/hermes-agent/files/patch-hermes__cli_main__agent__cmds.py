--- hermes_cli/main_agent_cmds.py.orig	2026-09-24 10:08:47 UTC
+++ hermes_cli/main_agent_cmds.py
@@ -168,6 +168,15 @@ def cmd_skills(args):
 
 
 def cmd_skills(args):
+    # Seed ~/.hermes/skills/ from the bundled library before any skills subcommand runs.
+    # The sync otherwise only fires from cmd_chat / cmd_gateway / cmd_dashboard, so a fresh
+    # install whose first command is `hermes skills list` reports zero skills and the user
+    # (reasonably) assumes something is broken.  On FreeBSD the port ships bundled skills
+    # under DATADIR and exposes the path via HERMES_BUNDLED_SKILLS; without this call the
+    # catalog stays empty until the user happens to run one of the other entrypoints.
+    from hermes_cli.main_tui_launch import _sync_bundled_skills_quietly
+    _sync_bundled_skills_quietly()
+
     from hermes_cli.main import _require_tty
     action = getattr(args, "skills_action", None)
     if action == "config":
