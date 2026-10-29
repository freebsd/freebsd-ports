Description: Use ConfigParser instead of SafeConfigParser, removed in Python
  3.12.
Issue ID: https://github.com/PagerDuty/pdagent/issues/178;
  fix: https://github.com/PagerDuty/pdagent/pull/184
Changeset: none
TODO: Drop once a release includes it.

--- pdagent/config.py.orig	2024-03-26 18:10:47 UTC
+++ pdagent/config.py
@@ -138,7 +138,7 @@ def load_agent_config():
 
     # Load config file
     try:
-        config = configparser.SafeConfigParser()
+        config = configparser.ConfigParser()
         config.read(conf_file)
     except configparser.Error as e:
         raise SystemExit(
