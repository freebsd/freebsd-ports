--- src/sema.c.orig	Sat Nov 24 13:48:16 2001
+++ src/sema.c	Sat Nov 24 14:53:39 2001
@@ -31,6 +31,11 @@
 
 #include "sema.h"
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if !(defined(BSD) && (BSD >= 199103))
        #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
        /* union semun is defined by including <sys/sem.h> */
        #else
@@ -42,6 +47,7 @@
                struct seminfo *__buf;      /* buffer for IPC_INFO */
        };
        #endif
+#endif
 
 #ifndef IPC_ALLOC
 #define IPC_ALLOC 0
@@ -201,7 +207,7 @@
 
    pthread_attr_init (&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
-   if(pthread_create(&thread_id,&thread_attr, (void*)sema_master,(void*)semid)!=0)
+   if(pthread_create(&thread_id,&thread_attr, sema_master,(void*)semid)!=0)
 	{
 		/* if the creation of the clock thread fails, release the master sema */
 		/* else nobody will try to create a new clock and all xfers will hang */
