--- tosvcd.c.orig	Fri Oct 25 12:15:12 2002
+++ tosvcd.c	Fri Oct 25 12:16:27 2002
@@ -29,9 +29,8 @@
 #include <time.h>
 #include <pthread.h>
 #include <list>
-#include <values.h>
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <glob.h>
 
 
@@ -1322,7 +1321,7 @@
       //  catch all signals
       //---------------------------------------------------
 #if 1
-      for (int i = 0; i < _NSIG; ++i) {
+      for (int i = 0; i < NSIG; ++i) {
             if (i != SIGABRT)
                   signal(i, catchSignal);
             }
