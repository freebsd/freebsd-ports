--- src/http/gskhttpheader.c.orig	Wed Apr 13 23:42:17 2005
+++ src/http/gskhttpheader.c	Sun May 15 01:56:00 2005
@@ -874,9 +874,9 @@
             + ACTUAL_LENGTH (opaque)
             + (is_md5 ? 0 : (strlen (algorithm) + 1));
   GskHttpAuthenticate *auth = g_malloc (len);
+  char *at;
   auth->mode = GSK_HTTP_AUTH_MODE_DIGEST;
   auth->auth_scheme_name = "Digest";
-  char *at;
   at = (char*)(auth + 1);
   auth->realm = at;
   at = g_stpcpy (at, realm) + 1;
