--- super.h.orig	2020-08-03 17:58:18 UTC
+++ super.h
@@ -290,7 +290,7 @@ typedef struct progList ProgList;
 
 /* ========================================================================= */
 #ifdef HAVE_ENUM
-enum {SUPER_AUTH_PASSWORD, SUPER_AUTH_PAM} Method;
+extern enum {SUPER_AUTH_PASSWORD, SUPER_AUTH_PAM} Method;
 #else
 /* No enums! */
 #define SUPER_AUTH_PASSWORD 1
