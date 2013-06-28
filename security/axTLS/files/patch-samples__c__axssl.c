--- ./samples/c/axssl.c.orig	2012-07-01 09:49:36.000000000 +0900
+++ ./samples/c/axssl.c	2013-04-10 16:59:23.000000000 +0900
@@ -45,6 +45,7 @@
  */
 #include <string.h>
 #include <stdio.h>
+#include <signal.h>
 #include <stdlib.h>
 #include "os_port.h"
 #include "ssl.h"
@@ -54,6 +55,14 @@
 #define STDIN_FILENO        0
 #endif
 
+/* enable features based on a 'super-set' capbaility. */
+#if defined(CONFIG_SSL_FULL_MODE) 
+#define CONFIG_SSL_ENABLE_CLIENT
+#define CONFIG_SSL_CERT_VERIFICATION
+#elif defined(CONFIG_SSL_ENABLE_CLIENT)
+#define CONFIG_SSL_CERT_VERIFICATION
+#endif
+
 static void do_server(int argc, char *argv[]);
 static void print_options(char *option);
 static void print_server_options(char *option);
