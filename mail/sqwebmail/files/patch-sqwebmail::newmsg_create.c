--- sqwebmail/newmsg_create.c.orig	Mon Mar 29 21:07:15 2004
+++ sqwebmail/newmsg_create.c	Mon Mar 29 21:07:41 2004
@@ -628,7 +628,7 @@
 {
 struct lookup_buffers *lookup_buffer_list=0;
 int	rc;
-char	*s=strdup(value);
+char	*s=rfc2047_decode_simple(value);
 
 	if (!s)	enomem();
 	rc=lookup_addressbook_do(header, s, &lookup_buffer_list);
