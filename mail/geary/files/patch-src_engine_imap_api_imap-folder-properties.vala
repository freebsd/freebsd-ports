diff --git src/engine/imap/api/imap-folder-properties.vala src/engine/imap/api/imap-folder-properties.vala
index 4b7b4b3..c062186 100644
--- src/engine/imap/api/imap-folder-properties.vala.orig
+++ src/engine/imap/api/imap-folder-properties.vala
@@ -67,7 +67,7 @@ public class Geary.Imap.FolderProperties : Geary.FolderProperties {
         // give the base class a zero email_unread, as the notion of "unknown" doesn't exist in
         // its contract
         base (messages, email_unread, Trillian.UNKNOWN, Trillian.UNKNOWN, Trillian.UNKNOWN, false,
-            false);
+            false, false);
         
         select_examine_messages = messages;
         status_messages = -1;
@@ -82,7 +82,7 @@ public class Geary.Imap.FolderProperties : Geary.FolderProperties {
     
     public FolderProperties.status(StatusData status, MailboxAttributes attrs) {
         base (status.messages, status.unseen, Trillian.UNKNOWN, Trillian.UNKNOWN, Trillian.UNKNOWN,
-            false, false);
+            false, false, false);
         
         select_examine_messages = -1;
         status_messages = status.messages;
@@ -213,5 +213,9 @@ public class Geary.Imap.FolderProperties : Geary.FolderProperties {
         // update base class value (which clients see)
         email_unread = count;
     }
+    
+    public void set_from_session_capabilities(Capabilities capabilities) {
+        create_never_returns_id = !capabilities.supports_uidplus();
+    }
 }
 
