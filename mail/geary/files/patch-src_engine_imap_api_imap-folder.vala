diff --git src/engine/imap/api/imap-folder.vala src/engine/imap/api/imap-folder.vala
index 71741ad..72c2c23 100644
--- src/engine/imap/api/imap-folder.vala.orig
+++ src/engine/imap/api/imap-folder.vala
@@ -95,6 +95,8 @@ private class Geary.Imap.Folder : BaseObject {
         session.status_response_received.connect(on_status_response);
         session.disconnected.connect(on_disconnected);
         
+        properties.set_from_session_capabilities(session.capabilities);
+        
         StatusResponse response = yield session.select_async(
             new MailboxSpecifier.from_folder_path(path, info.delim), cancellable);
         if (response.status != Status.OK) {
