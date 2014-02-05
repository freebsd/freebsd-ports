--- src/xitk/network.c.orig	2011-11-08 20:49:07.000000000 +0000
+++ src/xitk/network.c
@@ -24,7 +24,7 @@
 /* required for getsubopt(); the __sun test avoids compilation problems on 
     solaris. On FreeBSD defining this disable BSD functions to be visible
     and remove INADDR_NONE */
-#if ! defined (__sun__) && ! defined (__OpenBSD__)  && ! defined(__FreeBSD__) && ! defined(__APPLE__)
+#if ! defined (__sun__) && ! defined (__OpenBSD__)  && ! defined(__FreeBSD__) && ! defined(__APPLE__) && ! defined (__DragonFly__)
 #define _XOPEN_SOURCE 500
 #endif
 /* required for strncasecmp() */
@@ -64,8 +64,8 @@
 #include <netdb.h>
 #include <pthread.h>
 
-#include <readline.h>
-#include <history.h>
+#include <readline/readline.h>
+#include <readline/history.h>
 
 #include "common.h"
 
