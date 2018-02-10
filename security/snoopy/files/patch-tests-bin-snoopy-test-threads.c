--- tests/bin/snoopy-test-threads.c.orig	2017-12-26 01:38:15.298217000 +0800
+++ tests/bin/snoopy-test-threads.c	2017-12-26 01:41:42.177506000 +0800
@@ -307,7 +307,7 @@
     int          randomNr;
 
     // Seed
-    rndSeed = (unsigned int) (pthread_self() + getpid() + syscall(SYS_gettid) + time(NULL));
+    rndSeed = (unsigned int) ((unsigned int)pthread_self() + getpid() + time(NULL));
     srand(rndSeed);
 
     // Generate
