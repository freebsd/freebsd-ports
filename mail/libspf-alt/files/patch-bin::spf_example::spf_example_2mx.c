--- bin/spf_example/spf_example_2mx.c.orig	Sat Apr 10 00:08:39 2004
+++ bin/spf_example/spf_example_2mx.c	Fri May 28 23:00:10 2004
@@ -56,8 +56,12 @@
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
 
 
