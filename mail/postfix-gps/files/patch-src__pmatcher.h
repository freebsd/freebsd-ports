--- ./src/pmatcher.h.orig	2007-04-25 05:08:10.000000000 -0700
+++ ./src/pmatcher.h	2008-01-27 23:50:41.973446276 -0800
@@ -24,6 +24,7 @@
 #include <string>
 //getnameinfo
 #include <netdb.h>
+#include <sys/socket.h>
 //
 #include "regexcpp.h"
 #include "triplet.h"
