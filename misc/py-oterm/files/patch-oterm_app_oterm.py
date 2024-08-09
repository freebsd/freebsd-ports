--- oterm/app/oterm.py.orig	2024-05-15 16:35:57 UTC
+++ oterm/app/oterm.py
@@ -72,7 +72,7 @@ class OTerm(App):
             for id, name, model, context, system, format, keep_alive in saved_chats:
                 messages = await self.store.get_messages(id)
                 pane = TabPane(name, id=f"chat-{id}")
-                await pane.mount(
+                pane.compose_add_child(
                     ChatContainer(
                         db_id=id,
                         chat_name=name,
