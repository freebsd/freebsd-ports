--- lft_lib.h.orig	2017-07-04 09:02:47 UTC
+++ lft_lib.h
@@ -277,7 +277,7 @@ typedef struct _incomicmpicmp
 #define EVT_INCOMING_ICMP_ICMP		75
 #define EVT_RCVD_ICMP_ICMP		76
 
-#if defined(BSD_IP_STACK) && !defined(OPENBSD)
+#if defined(BSD_IP_STACK) && !defined(OPENBSD) && !defined(__FreeBSD__)
 #define SCREWED_IP_LEN
 #endif
 
