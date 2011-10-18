--- os/utils.c.orig	2010-05-04 02:48:00.000000000 +0200
+++ os/utils.c	2011-10-18 20:08:10.000000000 +0200
@@ -315,7 +315,7 @@
     FatalError("Could not create lock file in %s\n", tmp);
   (void) sprintf(pid_str, "%10ld\n", (long)getpid());
   (void) write(lfd, pid_str, 11);
-  (void) chmod(tmp, 0444);
+  (void) fchmod(tmp, 0444);
   (void) close(lfd);
 
   /*
@@ -336,7 +336,7 @@
       /*
        * Read the pid from the existing file
        */
-      lfd = open(LockFile, O_RDONLY);
+      lfd = open(LockFile, O_RDONLY|O_NOFOLLOW);
       if (lfd < 0) {
         unlink(tmp);
         FatalError("Can't read lock file %s\n", LockFile);
@@ -436,7 +436,11 @@
 
 #ifdef MONOTONIC_CLOCK
     struct timespec tp;
+#if defined(__FreeBSD__) && defined(CLOCK_MONOTONIC_FAST)
+    if (clock_gettime(CLOCK_MONOTONIC_FAST, &tp) == 0)
+#else
     if (clock_gettime(CLOCK_MONOTONIC, &tp) == 0)
+#endif
         return (tp.tv_sec * 1000) + (tp.tv_nsec / 1000000L);
 #endif
 
