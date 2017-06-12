--- src/client.c.orig	2003-06-20 10:39:31 UTC
+++ src/client.c
@@ -8,6 +8,7 @@
 #include <config.h>
 #endif
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <arpa/inet.h>
 #include <ctype.h>
