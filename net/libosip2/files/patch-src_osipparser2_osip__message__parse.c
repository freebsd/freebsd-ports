--- src/osipparser2/osip_message_parse.c.orig	2016-09-05 14:19:31 UTC
+++ src/osipparser2/osip_message_parse.c
@@ -784,6 +784,12 @@ msg_osip_body_parse (osip_message_t * sip, const char 
     if ('\n' == start_of_body[0] || '\r' == start_of_body[0])
       start_of_body++;
 
+    /* if message body is empty or contains a single CR/LF */
+    if (end_of_body <= start_of_body) {
+      osip_free (sep_boundary);
+      return OSIP_SYNTAXERROR;
+    }
+
     body_len = end_of_body - start_of_body;
 
     /* Skip CR before end boundary. */
