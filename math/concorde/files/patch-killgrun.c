--- TOOLS/killgrun.c.orig	Thu Dec 16 11:26:57 2004
+++ TOOLS/killgrun.c	Thu Dec 16 11:27:06 2004
@@ -75,13 +75,13 @@
         if (rval) {
             perror ("kill");
             fprintf (stderr, "Unable to kill process %d\n", process);
-/*
+#if 0
             if (errno == ESRCH) {   /* Does not work on Red Hat 8 */
                 fprintf (stderr, "Process does not exist, telling boss anyway\n");
             } else {
                 goto CLEANUP;
             }
-*/
+#endif
             fprintf (stderr, "Process does not exist, telling boss anyway\n");
         }
     }
