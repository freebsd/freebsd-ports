--- rfc822parse.c.orig	1996-06-04 13:37:01 UTC
+++ rfc822parse.c
@@ -86,7 +86,7 @@ parse_rfc822_message(struct message *m)
 
 
   /* Loop through rest of the message */
-  while ((linelen = getline(inbuf)) != 0)
+  while ((linelen = get_line(inbuf)) != 0)
     {
       if (inbuf->bodyend <= inbuf->offset &&
 	  inbuf->lineend <= inbuf->loffset)
