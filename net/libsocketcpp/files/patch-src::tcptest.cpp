$FreeBSD$

--- src/tcptest.cpp.orig	Sun Jun  9 16:03:19 2002
+++ src/tcptest.cpp	Sun Jun  9 16:03:31 2002
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include "tcpsocket.h"
 
 main() {
