--- bin/spf_example/spf_example.c.orig	Sat Apr 10 00:08:41 2004
+++ bin/spf_example/spf_example.c	Fri May 28 22:59:52 2004
@@ -55,8 +55,12 @@
 # include <arpa/inet.h>    /* in_addr struct */
 #endif
 
-#ifdef HAVE_GETOPT_H
-#include <getopt.h>
+#if defined(__FreeBSD__)
+#if (OSVERSION > 500000)
+#include "getopt.h"
+#else
+#include "unistd.h"
+#endif
 #endif
 
 
