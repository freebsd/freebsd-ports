--- src/tcpspray.c.orig	2010-05-01 01:08:34.000000000 -0700
+++ src/tcpspray.c	2015-02-15 15:56:55.904785304 -0800
@@ -34,6 +34,7 @@
 # define SIZE_MAX SIZE_T_MAX // FreeBSD 4.x workaround
 #endif
 #include <stdlib.h>
+#include <signal.h>
 
 #include <sys/types.h>
 #include <unistd.h>
