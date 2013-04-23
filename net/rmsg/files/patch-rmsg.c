--- rmsg.c	1992-11-23 16:27:09.000000000 -0500
+++ rmsg.c	2013-04-23 17:00:01.000000000 -0400
@@ -30,4 +30,6 @@
 #include <string.h>
 #endif
+#include <stdlib.h>
+#include <unistd.h>
 
 #include <pwd.h>
@@ -42,5 +44,2 @@
 #define HNLEN 200
 
-int xdr_rmsg(), getopt();
-char *getlogin(), *basename(), *index(), *rindex();
-uid_t getuid();
@@ -49,9 +51,4 @@
 void report();
 char *getalias(), *parseheader();
-#ifdef SUNOS
-void *malloc();
-#else
-char *malloc();
-#endif
 void storeout();
 extern struct hostent *gethostbyname();
@@ -72,9 +69,9 @@
 #endif
 
+int
 main(argc,argv)
 int argc;
 char **argv;
 {
-     extern char *optargs;
      extern int optind;
 
