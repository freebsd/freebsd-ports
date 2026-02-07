--- libfstt/arch.h.orig	2012-03-02 15:33:23 UTC
+++ libfstt/arch.h
@@ -48,6 +48,7 @@
 
 // architecture specific
 
+#include <sys/types.h>
 #include <netinet/in.h>
 
 // byte swapping (doing it by ntohl/ntohs works only on little endian CPUs)
