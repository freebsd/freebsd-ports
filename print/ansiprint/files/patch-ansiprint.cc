--- ./ansiprint.cc.orig	2014-02-04 20:01:43.741062023 +0100
+++ ./ansiprint.cc	2014-02-04 20:02:11.131060123 +0100
@@ -36,13 +36,14 @@
 #undef NOPRINT
 
 // INCLUDES
-#include <iostream.h>
+#include <iostream>
 #include <string.h> // Check to be sure we need this
 #include <stdlib.h>
 // below are the includes for raw I/O
 #include <fcntl.h>
 #include <unistd.h>
 
+using namespace std;
 
 /***** GLOBAL VARIABLE DECLARATIONS *****/
 
