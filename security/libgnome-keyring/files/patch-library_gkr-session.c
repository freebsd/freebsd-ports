--- library/gkr-session.c.orig	Sat Mar 31 14:59:37 2012
+++ library/gkr-session.c	Sat Oct 27 14:36:16 2012
@@ -44,6 +44,8 @@ struct _GkrSession {
 G_LOCK_DEFINE_STATIC (session_globals);
 static GkrSession *the_session;
 
+EGG_SECURE_DECLARE (session);
+
 static guchar*
 pkcs7_pad_string_in_secure_memory (const gchar *string, gsize *n_padded)
 {
