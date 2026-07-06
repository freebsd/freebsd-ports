--- src/uct/tcp/tcp.h.orig	2026-06-10 21:16:37 UTC
+++ src/uct/tcp/tcp.h
@@ -20,6 +20,7 @@
 #include <ucs/sys/iovec.h>
 
 #include <net/if.h>
+#include <netinet/in.h>
 
 #define UCT_TCP_NAME                          "tcp"
 
