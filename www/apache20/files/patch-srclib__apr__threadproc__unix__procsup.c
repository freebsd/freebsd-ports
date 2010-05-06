--- ./srclib/apr/threadproc/unix/procsup.c.orig	2006-09-20 12:04:09.000000000 -0400
+++ ./srclib/apr/threadproc/unix/procsup.c	2010-05-06 16:06:03.788832062 -0400
@@ -21,6 +21,7 @@
     int x;
 
     chdir("/");
+#ifndef FREEBSD_THREAD_HACK
 #if !defined(MPE) && !defined(OS2) && !defined(TPF) && !defined(BEOS)
     /* Don't detach for MPE because child processes can't survive the death of
      * the parent. */
@@ -56,6 +57,7 @@
         return errno;
     }
 #endif
+#endif
 
     /* close out the standard file descriptors */
     if (freopen("/dev/null", "r", stdin) == NULL) {
