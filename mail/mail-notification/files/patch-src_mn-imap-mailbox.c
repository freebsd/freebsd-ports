--- src/mn-imap-mailbox.c.orig	Tue Aug  9 22:01:56 2005
+++ src/mn-imap-mailbox.c	Wed Jan 25 19:22:48 2006
@@ -1646,7 +1646,12 @@
      */
     if (mn_ascii_validate(input))
       {
-	if (g_str_has_prefix(input, "+ "))
+	if (! strcmp(input, "+"))
+	  {
+	    response = g_new0(MNClientSessionResponse, 1);
+	    response->continuation = g_strdup("");
+	  }
+	else if (g_str_has_prefix(input, "+ "))
 	  {
 	    response = g_new0(MNClientSessionResponse, 1);
 	    response->continuation = g_strdup(input + 2);
