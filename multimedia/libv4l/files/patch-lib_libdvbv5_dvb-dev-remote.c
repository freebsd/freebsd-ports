--- lib/libdvbv5/dvb-dev-remote.c.orig	2020-04-09 16:29:54 UTC
+++ lib/libdvbv5/dvb-dev-remote.c
@@ -32,9 +32,11 @@
 #include <libudev.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdarg.h>
 #include <locale.h>
 #include <pthread.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <resolv.h>
 #include <string.h>
 #include <sys/socket.h>
