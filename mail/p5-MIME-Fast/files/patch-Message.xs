--- Fast/Message.xs.orig	2004-12-09 19:17:07.281250000 +0300
+++ Fast/Message.xs	2004-12-09 19:17:28.281250000 +0300
@@ -167,7 +167,7 @@
 void
 g_mime_message_set_mime_part(message, mime_part)
         MIME::Fast::Message	message
-        MIME::Fast::Part	mime_part
+        MIME::Fast::Object	mime_part
     CODE:
         g_mime_message_set_mime_part(message, GMIME_OBJECT (mime_part));
         plist = g_list_remove(plist, mime_part);
