--- participants.h.orig	Tue Jul 20 13:49:28 2004
+++ participants.h	Tue Jul 20 13:49:40 2004
@@ -3,6 +3,7 @@
 
 #define MAX_CLIENTS 1024
 
+#include <sys/types.h>
 #include <sys/socket.h>
 
 typedef struct participantsDb *participantsDb_t;
