--- include/usrinfo.h.orig	2004-06-26 01:53:38 UTC
+++ include/usrinfo.h
@@ -19,6 +19,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <stdlib.h>
+#include <string.h>
 //functions
 void uidtest(int argc,char** argv);
 void usrtest(int argc,char** argv);
