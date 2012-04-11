--- ./src/frontend/mosh-server.cc.orig	2012-04-02 18:08:49.000000000 -0400
+++ ./src/frontend/mosh-server.cc	2012-04-11 06:59:21.000000000 -0400
@@ -39,6 +39,7 @@
 #include <arpa/inet.h>
 #include <getopt.h>
 #include <time.h>
+#include <libutil.h>
 
 extern "C" {
 #include "selfpipe.h"
@@ -127,7 +128,7 @@
        && (strcmp( argv[ 1 ], "new" ) == 0) ) {
     /* new option syntax */
     int opt;
-    while ( (opt = getopt( argc, argv, "i:p:c:s" )) != -1 ) {
+    while ( (opt = getopt( argc - 1, argv + 1, "i:p:c:s" )) != -1 ) {
       switch ( opt ) {
       case 'i':
 	desired_ip = optarg;
