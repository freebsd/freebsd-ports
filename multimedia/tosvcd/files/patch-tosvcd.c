--- tosvcd.c.orig	Fri Sep 13 10:08:52 2002
+++ tosvcd.c	Mon Nov 18 16:56:27 2002
@@ -24,14 +24,12 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <string.h>
-#include <stdint.h>
 #include <sys/stat.h>
 #include <time.h>
 #include <pthread.h>
 #include <list>
-#include <values.h>
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <glob.h>
 
 
@@ -1322,7 +1320,7 @@
       //  catch all signals
       //---------------------------------------------------
 #if 1
-      for (int i = 0; i < _NSIG; ++i) {
+      for (int i = 0; i < NSIG; ++i) {
             if (i != SIGABRT)
                   signal(i, catchSignal);
             }
