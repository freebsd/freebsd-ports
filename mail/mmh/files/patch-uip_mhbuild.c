--- uip/mhbuild.c.orig	2020-08-21 13:38:24 UTC
+++ uip/mhbuild.c
@@ -51,7 +51,7 @@ char *version=VERSION;
 ** Directory to place tmp files.  This must
 ** be set before these routines are called.
 */
-char *tmp;
+extern char *tmp;
 
 pid_t xpid = 0;
 
