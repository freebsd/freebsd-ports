--- ./gmime/gmime-multipart-signed.c.orig	Mon May 19 15:02:05 2003
+++ ./gmime/gmime-multipart-signed.c	Mon May 19 15:02:16 2003
@@ -50,7 +50,7 @@
 static void multipart_signed_remove_header (GMimeObject *object, const char *header);
 static void multipart_signed_set_content_type (GMimeObject *object, GMimeContentType *content_type);
 static char *multipart_signed_get_headers (GMimeObject *object);
-static int multipart_signed_write_to_stream (GMimeObject *object, GMimeStream *stream);
+static ssize_t multipart_signed_write_to_stream (GMimeObject *object, GMimeStream *stream);
 
 
 static GMimeMultipartClass *parent_class = NULL;
