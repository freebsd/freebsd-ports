--- xsysstats.h.orig	Tue May 30 08:46:20 2000
+++ xsysstats.h	Sat Nov  9 08:43:29 2002
@@ -15,12 +15,9 @@
 #include <stdio.h>
 #include <sys/param.h>
 
-#include <stdio.h>
-#include <sys/param.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include <malloc.h>
 #include <netdb.h>
 #include <rpcsvc/rstat.h>
 
@@ -138,7 +135,7 @@
     char    *name;	/*Name of the host */
 #ifdef USE_NEW_RSTAT
     CLIENT  *client;	/* client connection for rstat */
-#endif USE_NEW_RSTAT
+#endif /* USE_NEW_RSTAT */
 };
 
 extern struct Xss_Window **windows;
