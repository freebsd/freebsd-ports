diff --git src/engine/imap-db/outbox/smtp-outbox-folder-properties.vala src/engine/imap-db/outbox/smtp-outbox-folder-properties.vala
index 1873439..535e3ef 100644
--- src/engine/imap-db/outbox/smtp-outbox-folder-properties.vala.orig
+++ src/engine/imap-db/outbox/smtp-outbox-folder-properties.vala
@@ -6,7 +6,7 @@
 
 private class Geary.SmtpOutboxFolderProperties : Geary.FolderProperties {
     public SmtpOutboxFolderProperties(int total, int unread) {
-        base (total, unread, Trillian.FALSE, Trillian.FALSE, Trillian.TRUE, true, false);
+        base (total, unread, Trillian.FALSE, Trillian.FALSE, Trillian.TRUE, true, false, false);
     }
     
     public void set_total(int total) {
