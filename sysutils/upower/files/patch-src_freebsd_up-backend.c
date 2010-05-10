--- src/freebsd/up-backend.c.orig	2010-05-09 13:40:33.000000000 -0400
+++ src/freebsd/up-backend.c	2010-05-09 13:42:27.000000000 -0400
@@ -298,16 +298,6 @@ up_backend_coldplug (UpBackend *backend,
 }
 
 /**
- * up_backend_get_powersave_command:
- **/
-const gchar *
-up_backend_get_powersave_command (UpBackend *backend, gboolean powersave)
-{
-	/* XXX: Do we want to use powerd here? */
-	return NULL;
-}
-
-/**
  * up_backend_get_suspend_command:
  **/
 const gchar *
