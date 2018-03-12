--- src/igmpproxy.h.orig	2018-02-13 19:17:30 UTC
+++ src/igmpproxy.h
@@ -35,9 +35,6 @@
 *   igmpproxy.h - Header file for common includes.
 */
 
-#include "config.h"
-#include "os.h"
-
 #include <errno.h>
 #include <stdarg.h>
 #include <stdio.h>
@@ -60,6 +57,9 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 
+#include "os.h"
+#include "config.h"
+
 /*
  * Limit on length of route data
  */
