--- plugins/atomic/app/atomic_svc.py.orig	2022-08-11 15:59:49 UTC
+++ plugins/atomic/app/atomic_svc.py
@@ -13,7 +13,7 @@ from app.utility.base_world import BaseWorld
 from app.utility.base_service import BaseService
 from app.objects.c_agent import Agent
 
-PLATFORMS = dict(windows='windows', macos='darwin', linux='linux')
+PLATFORMS = dict(windows='windows', macos='darwin', linux='linux', freebsd='freebsd')
 EXECUTORS = dict(command_prompt='cmd', sh='sh', powershell='psh', bash='sh')
 RE_VARIABLE = re.compile('(#{(.*?)})', re.DOTALL)
 PREFIX_HASH_LEN = 6
@@ -45,7 +45,7 @@ class AtomicService(BaseService):
         the `repo_url` parameter (eg. if you want to use a fork).
         """
         if not repo_url:
-            repo_url = 'https://github.com/redcanaryco/atomic-red-team.git'
+            repo_url = 'https://github.com/alonsobsd/atomic-red-team.git'
 
         if not os.path.exists(self.repo_dir) or not os.listdir(self.repo_dir):
             self.log.debug('cloning repo %s' % repo_url)
