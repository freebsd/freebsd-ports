--- libpatricia/patricia.c.orig	Wed Nov 27 09:51:16 2002
+++ libpatricia/patricia.c	Wed Nov 27 09:52:14 2002
@@ -24,6 +24,7 @@
 #include <stdio.h> /* sprintf, fprintf, stderr */
 #include <stdlib.h> /* free, atol, calloc */
 #include <string.h> /* memcpy, strchr, strlen */
+#include <sys/types.h>
 #include <arpa/inet.h> /* for inet_addr */
 
 #include "patricia.h"
