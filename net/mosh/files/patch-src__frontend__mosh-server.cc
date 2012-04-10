--- ./src/frontend/mosh-server.cc.orig	2012-04-02 18:08:49.000000000 -0400
+++ ./src/frontend/mosh-server.cc	2012-04-10 15:29:12.000000000 -0400
@@ -39,6 +39,7 @@
 #include <arpa/inet.h>
 #include <getopt.h>
 #include <time.h>
+#include <libutil.h>
 
 extern "C" {
 #include "selfpipe.h"
