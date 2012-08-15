--- panel-plugin/weather-http.c.orig	2012-08-02 21:16:17.000000000 +0000
+++ panel-plugin/weather-http.c	2012-08-12 19:28:36.000000000 +0000
@@ -32,6 +32,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #include <signal.h>
 #include <setjmp.h>
