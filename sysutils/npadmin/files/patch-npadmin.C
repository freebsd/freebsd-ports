--- npadmin.C.orig	Thu Nov 21 17:53:10 2002
+++ npadmin.C	Thu Nov 21 17:53:48 2002
@@ -11,6 +11,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 
+#define HAVE_DECL_GETOPT 1
 #ifdef HAVE_GETOPT_H
 #include <getopt.h>
 #else
