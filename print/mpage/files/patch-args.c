
$FreeBSD$

--- args.c.orig	Fri Aug  2 13:16:25 2002
+++ args.c	Fri Aug  2 13:17:06 2002
@@ -442,7 +442,6 @@
         libdir = env;
 
     if ((env = getenv("MPAGE")) != NULL) {
-        strcpy(copy, env);
         if ((copy = strdup(env)) == NULL) {
             fprintf(stderr, "%s: Unable to alloc memory for environment args\n",
                     MPAGE);
