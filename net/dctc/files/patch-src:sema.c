--- src/sema.c	Sat Nov 24 08:29:56 2001
+++ src/sema.c	Sun Dec  2 19:34:12 2001
@@ -29,8 +29,10 @@
 #include <limits.h>
 #include <pthread.h>
 
+#include "config.h"
 #include "sema.h"
 
+#if !(defined(BSD) && (BSD >= 199103))
        #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
        /* union semun is defined by including <sys/sem.h> */
        #else
@@ -42,6 +44,7 @@
                struct seminfo *__buf;      /* buffer for IPC_INFO */
        };
        #endif
+#endif
 
 #ifndef IPC_ALLOC
 #define IPC_ALLOC 0
