diff --git src/engine/imap-engine/imap-engine-generic-account.vala src/engine/imap-engine/imap-engine-generic-account.vala
index baec78f..4e0bdc4 100644
--- src/engine/imap-engine/imap-engine-generic-account.vala.orig
+++ src/engine/imap-engine/imap-engine-generic-account.vala
@@ -769,7 +769,7 @@ private abstract class Geary.ImapEngine.GenericAccount : Geary.AbstractAccount {
         // TODO: we should probably not use someone else's FQDN in something
         // that's supposed to be globally unique...
         Geary.RFC822.Message rfc822 = new Geary.RFC822.Message.from_composed_email(
-            composed, GMime.utils_generate_message_id(information.get_smtp_endpoint().host_specifier));
+            composed, GMime.utils_generate_message_id(information.get_smtp_endpoint().remote_address.hostname));
         
         // don't use create_email_async() as that requires the folder be open to use
         yield local.outbox.enqueue_email_async(rfc822, cancellable);
