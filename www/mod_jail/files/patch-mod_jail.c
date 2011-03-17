--- mod_jail.c.orig	2009-09-24 02:05:27.000000000 -0700
+++ mod_jail.c	2010-10-20 15:16:31.000000000 -0700
@@ -391,7 +391,7 @@
     if (p_addr == NULL) {
         return NULL;
     }
-    addr->s_addr = htonl(INADDR_LOOPBACK);
+    p_addr->s_addr = htonl(INADDR_LOOPBACK);
     cfg->jail = (struct jail) {
 	.version = JAIL_API_VERSION,
 	.path = NULL,
