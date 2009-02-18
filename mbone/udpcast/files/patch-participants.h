--- participants.h.orig	2005-12-22 23:59:18.000000000 +0100
+++ participants.h	2009-02-05 12:18:19.000000000 +0100
@@ -3,6 +3,10 @@
 
 #define MAX_CLIENTS 1024
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
+
 typedef struct participantsDb *participantsDb_t;
 
 #define isParticipantValid udpc_isParticipantValid
