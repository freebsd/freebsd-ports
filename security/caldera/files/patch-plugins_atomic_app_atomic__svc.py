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
