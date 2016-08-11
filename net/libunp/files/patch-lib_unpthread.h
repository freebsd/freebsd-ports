--- lib/unpthread.h.orig	1997-06-25 19:16:58 UTC
+++ lib/unpthread.h
@@ -4,7 +4,7 @@
 #ifndef	__unp_pthread_h
 #define	__unp_pthread_h
 
-#include	"unp.h"
+#include	<unp.h>
 
 void	Pthread_create(pthread_t *, const pthread_attr_t *,
 					   void * (*)(void *), void *);
