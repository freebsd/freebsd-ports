--- vchkpw.c.orig	Thu Jun 13 15:05:53 2002
+++ vchkpw.c	Thu Jun 13 15:06:16 2002
@@ -556,7 +556,7 @@
    pw_gid = pw->pw_gid;
    pw_dir = pw->pw_dir;
 #ifdef POP_AUTH_OPEN_RELAY
-   if ( (strcmp(LocalPort, "25") != 0) && (strcmp(LocalPort, "465") != 0)) {
+   if ( (LocalPort != 25) && (LocalPort != 465)) {
         open_smtp_relay();    
     }
 #endif
