--- src/capture.c.orig	Sat Feb 14 21:14:20 2004
+++ src/capture.c	Sat May 15 23:01:57 2004
@@ -643,7 +643,11 @@
             (*job->close) (fp);
         else if (job->flags & FLG_SYNC) {
             if (job->open == (void *(*)(char *, char*))fopen)
+#ifdef HAVE_FDATASYNC
                 fdatasync(fileno(fp));
+#else
+                fsync(fileno((FILE *) fp));
+#endif
         }
         
         /* substract the time we needed for creating and saving
