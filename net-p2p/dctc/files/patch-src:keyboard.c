--- src/keyboard.c	Sat Dec  1 08:53:15 2001
+++ src/keyboard.c	Sun Dec  2 19:34:12 2001
@@ -31,6 +31,9 @@
 #include <netdb.h>
 #include <glib.h>
 
+#include "config.h"
+
+#if !(defined(BSD) && (BSD >= 199103))
        #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
        /* union semun is defined by including <sys/sem.h> */
        #else
@@ -42,6 +45,7 @@
                struct seminfo *__buf;      /* buffer for IPC_INFO */
        };
        #endif
+#endif
 
 #include "dc_com.h"
 #include "display.h"
