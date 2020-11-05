--- libmailutils/imapio/flags.c.orig	2020-05-28 14:03:57 UTC
+++ libmailutils/imapio/flags.c
@@ -34,7 +34,7 @@ _imap4_attrlist[] =
   { "\\Flagged", MU_ATTRIBUTE_FLAGGED },
   { "\\Deleted", MU_ATTRIBUTE_DELETED },
   { "\\Draft", MU_ATTRIBUTE_DRAFT },
-  { "\\Seen", MU_ATTRIBUTE_SEEN|MU_ATTRIBUTE_READ },
+  { "\\Seen", MU_ATTRIBUTE_READ },
 };
 
 static int _imap4_nattr = MU_ARRAY_SIZE (_imap4_attrlist);
