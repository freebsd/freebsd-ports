--- src/up-polkit.c.orig	2010-04-08 21:38:56.000000000 -0400
+++ src/up-polkit.c	2010-04-09 02:48:12.000000000 -0400
@@ -69,7 +69,7 @@ up_polkit_check_auth (UpPolkit *polkit, 
 {
 	gboolean ret = FALSE;
 	GError *error;
-	GError *error_local;
+	GError *error_local = NULL;
 	PolkitAuthorizationResult *result;
 
 	/* check auth */
@@ -104,7 +104,7 @@ up_polkit_is_allowed (UpPolkit *polkit, 
 {
 	gboolean ret = FALSE;
 	GError *error;
-	GError *error_local;
+	GError *error_local = NULL;
 	PolkitAuthorizationResult *result;
 
 	/* check auth */
