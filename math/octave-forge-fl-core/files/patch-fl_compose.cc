--- fl_compose.cc.orig	2013-11-16 22:48:40.000000000 +0100
+++ fl_compose.cc	2013-11-16 22:48:58.000000000 +0100
@@ -20,6 +20,7 @@
 
 #include <octave/oct.h>
 #include <octave/parse.h>
+#include <unistd.h>
 #include <pthread.h>    
 
 #define HELP \
