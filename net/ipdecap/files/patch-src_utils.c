--- src/utils.c.orig	2018-07-19 13:30:02 UTC
+++ src/utils.c
@@ -19,6 +19,7 @@
 */
 
 #include "utils.h"
+#include <sys/types.h>
 #include <net/ethernet.h>  // for ETHER_ADDR_LEN
 #include <stdarg.h>        // for va_list
 #include <stdio.h>         // for printf, NULL, vfprintf, stdout
