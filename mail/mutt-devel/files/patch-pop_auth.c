--- pop_auth.c.orig	Thu Jul 17 19:42:53 2003
+++ pop_auth.c	Thu Jul 17 19:46:01 2003
@@ -206,12 +206,12 @@
   mutt_message _("Authenticating (APOP)...");
 
   /* Compute the authentication hash to send to the server */
-  MD5Init (&mdContext);
-  MD5Update (&mdContext, (unsigned char *)pop_data->timestamp,
+  MD5_Init (&mdContext);
+  MD5_Update (&mdContext, (unsigned char *)pop_data->timestamp,
 	     strlen (pop_data->timestamp));
-  MD5Update (&mdContext, (unsigned char *)pop_data->conn->account.pass,
+  MD5_Update (&mdContext, (unsigned char *)pop_data->conn->account.pass,
 	     strlen (pop_data->conn->account.pass));
-  MD5Final (digest, &mdContext);
+  MD5_Final (digest, &mdContext);
 
   for (i = 0; i < sizeof (digest); i++)
     sprintf (hash + 2 * i, "%02x", digest[i]);
