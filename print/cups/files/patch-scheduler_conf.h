--- scheduler/conf.h.orig	2025-11-27 15:21:54 UTC
+++ scheduler/conf.h
@@ -244,10 +244,8 @@ VAR char		*ServerKeychain		VALUE(NULL);
 					/* Keychain holding cert + key */
 #endif /* HAVE_TLS */
 
-#ifdef HAVE_ONDEMAND
 VAR int			IdleExitTimeout		VALUE(60);
 					/* Time after which an idle cupsd will exit */
-#endif /* HAVE_ONDEMAND */
 
 #ifdef HAVE_AUTHORIZATION_H
 VAR char		*SystemGroupAuthKey	VALUE(NULL);
