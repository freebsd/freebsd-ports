--- srclib/apr/threadproc/unix/procsup.c.orig	Mon Apr  8 22:08:18 2002
+++ srclib/apr/threadproc/unix/procsup.c	Sun Jul 21 08:45:44 2002
@@ -59,6 +59,7 @@
     int x;
 
     chdir("/");
+#ifndef FREEBSD_THREAD_HACK
 #if !defined(MPE) && !defined(OS2) && !defined(TPF) && !defined(BEOS)
     /* Don't detach for MPE because child processes can't survive the death of
      * the parent. */
@@ -89,6 +90,7 @@
     if (setpgid(0, 0) == -1) {
         return errno;
     }
+#endif
 #endif
 
     /* close out the standard file descriptors */
