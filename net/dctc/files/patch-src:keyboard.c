--- src/keyboard.c.orig	Sat Nov 24 13:29:15 2001
+++ src/keyboard.c	Sat Nov 24 13:43:51 2001
@@ -31,6 +31,7 @@
 #include <netdb.h>
 #include <glib.h>
 
+#if !(defined(BSD) && (BSD >= 199103))
        #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
        /* union semun is defined by including <sys/sem.h> */
        #else
@@ -42,6 +43,7 @@
                struct seminfo *__buf;      /* buffer for IPC_INFO */
        };
        #endif
+#endif
 
 #include "dc_com.h"
 #include "display.h"
