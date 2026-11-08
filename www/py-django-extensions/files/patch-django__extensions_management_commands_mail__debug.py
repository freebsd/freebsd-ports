Description: asyncio.get_event_loop() raises RuntimeError on Python 3.14
  when no event loop is set, so mail_debug failed to start. Create and set
  the loop explicitly.
Issue ID: none
Changeset: none (upstream main has the same code)
TODO: Submit upstream; drop once a release includes the fix.

--- django_extensions/management/commands/mail_debug.py.orig	2025-04-05 17:36:22 UTC
+++ django_extensions/management/commands/mail_debug.py
@@ -94,7 +94,8 @@ class Command(BaseCommand):
             handler = CustomHandler()
             controller = Controller(handler, hostname=addr, port=port)
             controller.start()
-            loop = asyncio.get_event_loop()
+            loop = asyncio.new_event_loop()
+            asyncio.set_event_loop(loop)
             loop.run_forever()
 
         try:
