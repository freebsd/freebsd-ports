--- tests/bin/snoopy-test-threads.c.orig	2016-09-14 15:02:26 UTC
+++ tests/bin/snoopy-test-threads.c
@@ -25,7 +25,6 @@
 /*
  * Includes order: from local to global
  */
-#define   _XOPEN_SOURCE   500
 #define   _GNU_SOURCE
 
 #include <snoopy.h>
@@ -42,7 +41,7 @@
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <wait.h>
+#include <sys/wait.h>
 
 
 
@@ -307,7 +306,7 @@ int randomNumberInclusive (int nMin, int
     int          randomNr;
 
     // Seed
-    rndSeed = (unsigned int) (pthread_self() + getpid() + syscall(SYS_gettid) + time(NULL));
+    rndSeed = (unsigned int) ((unsigned int)pthread_self() + getpid() + time(NULL));
     srand(rndSeed);
 
     // Generate
