--- dl.c.orig	2014-08-12 18:52:40.000000000 +0200
+++ dl.c	2014-08-12 18:55:42.000000000 +0200
@@ -1,3 +1,6 @@
+#ifdef __FreeBSD__
+#include <stdio.h>
+#endif
 #define _FILE_OFFSET_BITS 64
 #define _GNU_SOURCE
 #include "socket.h"
