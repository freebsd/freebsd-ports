--- ./src/drv_imap.c.orig	Wed Nov  1 08:15:09 2006
+++ ./src/drv_imap.c	Wed Dec 27 21:43:01 2006
@@ -26,6 +26,7 @@
 
 #include <assert.h>
 #include <unistd.h>
+#include <limits.h>
 #include <sys/mman.h>
 #include <sys/time.h>
 #include <stdlib.h>
@@ -1243,9 +1244,7 @@
 	} else {
 		memset( &addr, 0, sizeof(addr) );
 		addr.sin_port = htons( srvc->port ? srvc->port :
-#ifdef HAVE_LIBSSL
 		                       srvc->use_imaps ? 993 :
-#endif
 		                       143 );
 		addr.sin_family = AF_INET;
 
