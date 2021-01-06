--- nasl/nasl_builtin_find_service.c	2020-12-31 21:25:42.383545000 -0500
+++ nasl/nasl_builtin_find_service.c	2020-12-31 21:26:14.781948000 -0500
@@ -34,6 +34,7 @@
 #include <string.h>    /* for strstr() */
 #include <sys/time.h>  /* for gettimeofday() */
 #include <sys/types.h> /* for waitpid() */
+#include <sys/socket.h>
 #include <sys/wait.h>  /* for waitpid() */
 #include <unistd.h>    /* for usleep() */
 
