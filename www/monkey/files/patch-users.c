--- src/user.c.orig	Sat Oct 18 22:21:54 2003
+++ src/user.c	Mon Oct 20 17:26:55 2003
@@ -23,6 +23,7 @@
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #include "monkey.h"
@@ -79,7 +80,7 @@
 		/* Just if i'm superuser */
 		rl.rlim_max= (256 * config->maxclients);
 		rl.rlim_cur = rl.rlim_max;
-	    setrlimit( RLIMIT_OFILE, &rl );
+	    setrlimit( RLIMIT_NOFILE, &rl );
     
       /* Chequear si existe el usuario USER ... */
       if ((usr = getpwnam( config->user )) == NULL) {
