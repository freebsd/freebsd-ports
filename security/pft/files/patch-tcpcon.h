--- tcpcon.h.orig	Thu Aug  5 13:40:47 2004
+++ tcpcon.h	Thu Aug  5 13:40:58 2004
@@ -9,7 +9,7 @@
 #else 
 #include <netinet/in.h>
 #include <sys/time.h>
-#endif UNIX
+#endif // UNIX
 
 #include "rawmem.h"
 #include "exceptions.h"
@@ -101,4 +101,4 @@
 		bool			connected;
 };
 
-#endif __TCPCON_H__
+#endif // __TCPCON_H__
