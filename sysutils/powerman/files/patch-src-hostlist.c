$FreeBSD$

--- src/hostlist.c.orig	Mon Mar 29 13:50:02 2004
+++ src/hostlist.c	Mon Mar 29 13:50:18 2004
@@ -43,7 +43,7 @@
 #include <assert.h>
 #include <errno.h>
 #include <ctype.h>
-#include <sys/param.h>
+#include <limits.h>
 #include <unistd.h>
 
 #include "hostlist.h"
