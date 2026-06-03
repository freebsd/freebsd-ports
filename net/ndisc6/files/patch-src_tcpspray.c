--- src/tcpspray.c.orig	2016-12-07 16:43:04 UTC
+++ src/tcpspray.c
@@ -33,6 +33,7 @@
 # define SIZE_MAX SIZE_T_MAX // FreeBSD 4.x workaround
 #endif
 #include <stdlib.h>
+#include <signal.h>
 
 #include <sys/types.h>
 #include <unistd.h>
