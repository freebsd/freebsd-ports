--- paicc.c	1996-09-02 18:16:39.000000000 -0700
+++ paicc.c	2014-05-10 19:41:55.568980139 -0700
@@ -59,10 +59,14 @@
 
 */
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <curses.h>
 #include <signal.h>
 #include <time.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <sys/wait.h>
 
 #include "evap/evap.h"
 #include "evap/paicc_pdt_out"
@@ -483,6 +487,7 @@
 
 } /* end window_ini */
 
+int
 main(argc, argv)
   int argc;
   char *argv[];
