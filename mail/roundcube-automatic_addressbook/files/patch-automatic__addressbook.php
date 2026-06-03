--- automatic_addressbook.php.orig	2017-01-26 08:10:28 UTC
+++ automatic_addressbook.php
@@ -129,9 +129,9 @@ class automatic_addressbook extends rcube_plugin
             );
         } else {
             $all_recipients = array_merge(
-                rcube_mime::decode_address_list($headers['To'], null, true, $headers['charset']),
-                rcube_mime::decode_address_list($headers['Cc'], null, true, $headers['charset']),
-                rcube_mime::decode_address_list($headers['Bcc'], null, true, $headers['charset'])
+                @rcube_mime::decode_address_list($headers['To'], null, true, $headers['charset']),
+                @rcube_mime::decode_address_list($headers['Cc'], null, true, $headers['charset']),
+                @rcube_mime::decode_address_list($headers['Bcc'], null, true, $headers['charset'])
             );
         }
 
@@ -284,7 +284,7 @@ class automatic_addressbook extends rcube_plugin
         if ($args['source'] !== $this->abook_id) {
             foreach (array('email:home', 'email:work', 'email:other') as $email_field) {
                 // Would trigger a warning with rc 0.5 without this if
-                if ($args['record'][$email_field]) {
+                if (@$args['record'][$email_field]) {
                     foreach ($args['record'][$email_field] as $email) {
                         $contact_emails[] = $email;
                     }
