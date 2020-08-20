Index: src/auth.h
===================================================================
--- src/auth.h	(revision 2271)
+++ src/auth.h	(revision 2272)
@@ -240,8 +240,6 @@ struct auth {
 };
 typedef struct auth *Auth;
 
-struct radiusconf radius;		/* RADIUS configuration */
-
  /*
   * Interface between the auth-backend (secret file, RADIUS, etc.) and Mpd's
   * internal structs.
