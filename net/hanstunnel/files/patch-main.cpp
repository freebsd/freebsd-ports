--- main.cpp.orig	2014-08-06 10:11:00.000000000 -0400
+++ main.cpp	2014-08-06 10:11:12.000000000 -0400
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <syslog.h>
+#include <unistd.h>
 
 void usage()
 {
