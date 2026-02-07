--- plugins/atomic/app/atomic_svc.py.orig	2024-02-13 20:49:23 UTC
+++ plugins/atomic/app/atomic_svc.py
@@ -5,6 +5,7 @@ import os
 import re
 import shutil
 import yaml
+import platform
 
 from collections import defaultdict
 from subprocess import DEVNULL, STDOUT, check_call
@@ -13,7 +14,7 @@ from app.utility.base_world import BaseWorld
 from app.utility.base_service import BaseService
 from app.objects.c_agent import Agent
 
-PLATFORMS = dict(windows='windows', macos='darwin', linux='linux')
+PLATFORMS = dict(windows='windows', macos='darwin', linux='linux', freebsd='freebsd')
 EXECUTORS = dict(command_prompt='cmd', sh='sh', powershell='psh', bash='sh')
 RE_VARIABLE = re.compile('(#{(.*?)})', re.DOTALL)
 PREFIX_HASH_LEN = 6
@@ -45,11 +46,17 @@ class AtomicService(BaseService):
         the `repo_url` parameter (eg. if you want to use a fork).
         """
         if not repo_url:
-            repo_url = 'https://github.com/redcanaryco/atomic-red-team.git'
+            if platform.system() == "FreeBSD":
+                repo_url = 'https://github.com/alonsobsd/atomic-red-team.git'
+            else:
+                repo_url = 'https://github.com/redcanaryco/atomic-red-team.git'
 
         if not os.path.exists(self.repo_dir) or not os.listdir(self.repo_dir):
             self.log.debug('cloning repo %s' % repo_url)
-            check_call(['git', 'clone', '--depth', '1', repo_url, self.repo_dir], stdout=DEVNULL, stderr=STDOUT)
+            if platform.system() == "FreeBSD":
+                check_call(['git', 'clone', '-b', 'atomic', '--depth', '1', repo_url, self.repo_dir], stdout=DEVNULL, stderr=STDOUT)
+            else:
+                check_call(['git', 'clone', '--depth', '1', repo_url, self.repo_dir], stdout=DEVNULL, stderr=STDOUT)
             self.log.debug('clone complete')
 
     async def populate_data_directory(self, path_yaml=None):
@@ -132,6 +139,11 @@ class AtomicService(BaseService):
             return path.replace('\\', '/')
         return path
 
+    @staticmethod
+    def _platform_system():
+        _platform = platform.system()
+        return _platform
+
     def _catch_path_to_atomics_folder(self, string_to_analyse, platform):
         """
         Catch a path to the atomics/ folder in the `string_to_analyse` variable,
@@ -302,6 +314,10 @@ class AtomicService(BaseService):
         Return True if an ability was saved.
         """
         ability_id = hashlib.md5(json.dumps(test).encode()).hexdigest()
+        list_name = 'supported_platforms'
+
+        if self._platform_system() == 'FreeBSD':
+            list_name = 'run_on'
 
         tactics_li = self.technique_to_tactics.get(entries['attack_technique'], ['redcanary-unknown'])
         tactic = 'multiple' if len(tactics_li) > 1 else tactics_li[0]
@@ -317,7 +333,8 @@ class AtomicService(BaseService):
             ),
             platforms=dict()
         )
-        for p in test['supported_platforms']:
+
+        for p in test[list_name]:
             if test['executor']['name'] != 'manual':
                 # manual tests are expected to be run manually by a human, no automation is provided
                 executor = EXECUTORS.get(test['executor']['name'], 'unknown')
