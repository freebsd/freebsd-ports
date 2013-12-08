--- examples/forkjoin/forkjoin.cc.orig	2013-11-16 20:05:10.000000000 +0100
+++ examples/forkjoin/forkjoin.cc	2013-11-16 20:05:29.000000000 +0100
@@ -5,6 +5,7 @@
 
 /* defines and prototypes for the PVM++ and PVM libraries */
 
+#include <stdlib.h>
 #include <pvm++/pvm++.hh>
 
 /* Maximum number of children this program will spawn */
