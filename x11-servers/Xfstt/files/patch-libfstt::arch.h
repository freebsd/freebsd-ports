--- libfstt/arch.h.orig	Thu Nov 14 21:08:10 2002
+++ libfstt/arch.h	Wed Nov 20 22:44:27 2002
@@ -49,6 +49,7 @@
 typedef signed short	S16;
 typedef signed int	S32;
 
+#include <sys/types.h>
 #include <netinet/in.h>
 
 // byte swapping (doing it by ntohl/ntohs works only on little endian CPUs)
