--- imap/message.c.orig	2007-05-23 03:17:53.000000000 +0200
+++ imap/message.c	2013-06-04 00:53:42.000000000 +0200
@@ -435,7 +435,7 @@
   rewind (fp);
   
   imap_munge_mbox_name (mbox, sizeof (mbox), mailbox);
-  snprintf (buf, sizeof (buf), "APPEND %s (\\Seen) {%d}", mbox, len);
+  snprintf (buf, sizeof (buf), "APPEND %s (\\Seen) {%lu}", mbox, (unsigned long)len);
 
   imap_cmd_start (idata, buf);
 
