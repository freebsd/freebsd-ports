--- src/igmpproxy.c.orig	2017-12-22 20:49:54 UTC
+++ src/igmpproxy.c
@@ -37,11 +37,6 @@
 *   February 2005 - Johnny Egeland
 */
 
-/* getopt() and clock_getime() */
-#ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 200112L
-#endif
-
 #include "igmpproxy.h"
 
 static const char Usage[] =
