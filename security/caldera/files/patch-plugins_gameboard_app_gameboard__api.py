--- plugins/gameboard/app/gameboard_api.py.orig	2021-12-22 15:33:52 UTC
+++ plugins/gameboard/app/gameboard_api.py
@@ -244,7 +244,7 @@ class GameboardApi(BaseService):
         reference_ability = (await self.data_svc.locate('abilities', match=dict(ability_id='bf565e6a-0037-4aa4-852f-1afa222c76db')))[0]  #TODO: replace
         ability_id = str(uuid.uuid4())
         executors = []
-        for pl in ['windows', 'darwin', 'linux']:
+        for pl in ['windows', 'darwin', 'linux', 'freebsd']:
             reference_executor = reference_ability.find_executor('elasticsearch', pl)
             if not reference_executor:
                 continue
