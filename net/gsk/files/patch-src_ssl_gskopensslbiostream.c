--- src/ssl/gskopensslbiostream.c.orig	2006-05-17 18:39:31 UTC
+++ src/ssl/gskopensslbiostream.c
@@ -106,7 +106,7 @@ bio_gsk_stream_pair_bwrite (BIO *bio,
 		       const char *out,
 		       int length)
 {
-  GskBufferStream *buffer_stream = GSK_BUFFER_STREAM (bio->ptr);
+  GskBufferStream *buffer_stream = GSK_BUFFER_STREAM (BIO_get_data(bio));
   DEBUG_BIO("bio_gsk_stream_pair_bwrite: writing %d bytes to read-buffer of backend", length);
   gsk_buffer_append (gsk_buffer_stream_peek_read_buffer (buffer_stream), out, length);
   gsk_buffer_stream_read_buffer_changed (buffer_stream);
@@ -118,7 +118,7 @@ bio_gsk_stream_pair_bread (BIO *bio,
 		      char *in,
 		      int max_length)
 {
-  GskBufferStream *buffer_stream = GSK_BUFFER_STREAM (bio->ptr);
+  GskBufferStream *buffer_stream = GSK_BUFFER_STREAM (BIO_get_data(bio));
   guint length = gsk_buffer_read (gsk_buffer_stream_peek_write_buffer (buffer_stream), in, max_length);
   DEBUG_BIO("bio_gsk_stream_pair_bread: read %u bytes of %d bytes from backend write buffer", length, max_length);
   if (length > 0)
@@ -132,7 +132,7 @@ bio_gsk_stream_pair_ctrl (BIO  *bio,
 		     long  num,
 		     void *ptr)
 {
-  GskBufferStreamOpenssl *openssl_buffer_stream = GSK_BUFFER_STREAM_OPENSSL (bio->ptr);
+  GskBufferStreamOpenssl *openssl_buffer_stream = GSK_BUFFER_STREAM_OPENSSL (BIO_get_data(bio));
   g_assert (openssl_buffer_stream->bio == bio);
 
   DEBUG_BIO("bio_gsk_stream_pair_ctrl: called with cmd=%d", cmd);
@@ -161,27 +161,26 @@ bio_gsk_stream_pair_create (BIO *bio)
 static int 
 bio_gsk_stream_pair_destroy (BIO *bio)
 {
-  GskBufferStream *buffer_stream = GSK_BUFFER_STREAM (bio->ptr);
+  GskBufferStream *buffer_stream = GSK_BUFFER_STREAM (BIO_get_data(bio));
   DEBUG_BIO("bio_gsk_stream_pair_destroy (%p)", bio);
   if (buffer_stream == NULL)
     return FALSE;
   g_object_unref (buffer_stream);
-  bio->ptr = NULL;
+  BIO_set_data(bio, NULL);
   return TRUE;
 }
 
-static BIO_METHOD bio_method_gsk_stream_pair =
+static BIO_METHOD *bio_method_gsk_stream_pair = NULL;
+
+static BIO_METHOD *create_bio_method_gsk_stream_pair(void)
 {
-  22,				/* type:  this is quite a hack */
-  "GskStream-BIO",		/* name */
-  bio_gsk_stream_pair_bwrite,	/* bwrite */
-  bio_gsk_stream_pair_bread,	/* bread */
-  NULL,				/* bputs */
-  NULL,				/* bgets */
-  bio_gsk_stream_pair_ctrl,	/* ctrl */
-  bio_gsk_stream_pair_create,	/* create */
-  bio_gsk_stream_pair_destroy,	/* destroy */
-  NULL				/* callback_ctrl */
+  BIO_METHOD *bm = BIO_meth_new(BIO_get_new_index(), "GskStream-BIO");
+  BIO_meth_set_write(bm, bio_gsk_stream_pair_bwrite);
+  BIO_meth_set_read(bm, bio_gsk_stream_pair_bread);
+  BIO_meth_set_ctrl(bm, bio_gsk_stream_pair_ctrl);
+  BIO_meth_set_create(bm, bio_gsk_stream_pair_create);
+  BIO_meth_set_destroy(bm, bio_gsk_stream_pair_destroy);
+  return bm;
 };
 
 
@@ -207,9 +206,11 @@ gsk_openssl_bio_stream_pair (BIO              **bio_ou
 {
   GskBufferStreamOpenssl *openssl_stream = g_object_new (GSK_TYPE_BUFFER_STREAM_OPENSSL, NULL);
   GskStream *stream = GSK_STREAM (openssl_stream);
-  *bio_out = BIO_new (&bio_method_gsk_stream_pair);
-  (*bio_out)->ptr = g_object_ref (stream);
-  (*bio_out)->init = TRUE;		/// HMM...
+  if (bio_method_gsk_stream_pair == NULL)
+    bio_method_gsk_stream_pair = create_bio_method_gsk_stream_pair();
+  *bio_out = BIO_new (bio_method_gsk_stream_pair);
+  BIO_set_data(*bio_out, g_object_ref (stream));
+  BIO_set_init(*bio_out, TRUE);		/// HMM...
   *stream_out = GSK_BUFFER_STREAM (stream);
   openssl_stream->bio = *bio_out;
   return TRUE;
