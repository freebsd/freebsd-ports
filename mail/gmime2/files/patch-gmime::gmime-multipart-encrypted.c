--- ./gmime/gmime-multipart-encrypted.c.orig	Mon May 19 14:05:11 2003
+++ ./gmime/gmime-multipart-encrypted.c	Mon May 19 14:05:25 2003
@@ -54,7 +54,7 @@
 static void multipart_encrypted_remove_header (GMimeObject *object, const char *header);
 static void multipart_encrypted_set_content_type (GMimeObject *object, GMimeContentType *content_type);
 static char *multipart_encrypted_get_headers (GMimeObject *object);
-static int multipart_encrypted_write_to_stream (GMimeObject *object, GMimeStream *stream);
+static ssize_t multipart_encrypted_write_to_stream (GMimeObject *object, GMimeStream *stream);
 
 
 static GMimeMultipartClass *parent_class = NULL;
