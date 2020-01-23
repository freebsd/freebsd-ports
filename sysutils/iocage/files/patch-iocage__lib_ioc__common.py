Originates here
https://github.com/iocage/iocage/commit/753b2f35731423597d7f51f33427b6d619fcd0b5
https://github.com/iocage/iocage/pull/1106
and most likely can be removed on the next release of iocage.
--- iocage_lib/ioc_common.py.orig	2019-09-26 07:23:24 UTC
+++ iocage_lib/ioc_common.py
@@ -44,6 +44,9 @@ import iocage_lib.ioc_exceptions
 import iocage_lib.ioc_exec
 
 INTERACTIVE = False
+# 4 is a magic number for default and doesn't refer
+# to the actual ruleset 4 in devfs.rules(!)
+IOCAGE_DEVFS_RULESET = 4
 
 
 def callback(_log, callback_exception):
@@ -737,7 +740,7 @@ def generate_devfs_ruleset(conf, paths=N
     Will add a per jail devfs ruleset with the specified rules,
     specifying defaults that equal devfs_ruleset 4
     """
-    ruleset = conf['devfs_ruleset']
+    configured_ruleset = conf['devfs_ruleset']
     devfs_includes = []
     devfs_rulesets = su.run(
         ['devfs', 'rule', 'showsets'],
@@ -745,22 +748,26 @@ def generate_devfs_ruleset(conf, paths=N
     )
     ruleset_list = [int(i) for i in devfs_rulesets.stdout.splitlines()]
 
-    if ruleset != '4':
-        if int(ruleset) in ruleset_list:
-            return str(ruleset)
-
-        logit({
-            "level": "INFO",
-            "message": f'* Ruleset {ruleset} does not exist, using defaults'
-        },
-            _callback=callback,
-            silent=silent)
-
-    ruleset = 5  # 0-4 is always reserved
+    ruleset = int(conf["min_dyn_devfs_ruleset"])
     while ruleset in ruleset_list:
         ruleset += 1
     ruleset = str(ruleset)
 
+    # Custom devfs_ruleset configured, clone to dynamic ruleset
+    if int(configured_ruleset) != IOCAGE_DEVFS_RULESET:
+        if int(configured_ruleset) not in ruleset_list:
+            return (True, configured_ruleset, '0')
+        rules = su.run(
+            ['devfs', 'rule', '-s', configured_ruleset, 'show'],
+            stdout=su.PIPE, universal_newlines=True
+        )
+        for rule in rules.stdout.splitlines():
+            su.run(['devfs', 'rule', '-s', ruleset, 'add'] +
+                   rule.split(' ')[1:], stdout=su.PIPE)
+
+        return (True, configured_ruleset, ruleset)
+
+    # Create default ruleset
     devfs_dict = dict((dev, None) for dev in (
         'hide', 'null', 'zero', 'crypto', 'random', 'urandom', 'ptyp*',
         'ptyq*', 'ptyr*', 'ptys*', 'ptyP*', 'ptyQ*', 'ptyR*', 'ptyS*', 'ptyl*',
@@ -812,7 +819,7 @@ def generate_devfs_ruleset(conf, paths=N
 
         su.run(['devfs', 'rule', '-s', ruleset] + path, stdout=su.PIPE)
 
-    return ruleset
+    return (False, configured_ruleset, ruleset)
 
 
 def runscript(script):
