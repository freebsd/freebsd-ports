--- helper.c.orig	Tue Oct 26 15:49:48 2004
+++ helper.c	Tue Oct 26 15:53:43 2004
@@ -23,6 +23,8 @@
 #include <sys/utsname.h>
 #include <string.h>
 #include <ctype.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 #include "helper.h"
