--- matchiprange.c.orig	2009-04-10 18:17:38.000000000 +0200
+++ matchiprange.c	2009-04-10 18:17:58.000000000 +0200
@@ -17,6 +17,7 @@
 #include <fmt.h>
 #include <ctype.h>
 #include <ip6.h>
+#include <string.h>
 
 char _buf[8192];
 
