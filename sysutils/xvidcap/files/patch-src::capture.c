--- src/capture.c.orig	Sat Feb 14 21:14:20 2004
+++ src/capture.c	Sun Apr 25 01:21:53 2004
@@ -643,7 +643,11 @@
             (*job->close) (fp);
         else if (job->flags & FLG_SYNC) {
             if (job->open == (void *(*)(char *, char*))fopen)
+#ifdef HAVE_FDATASYNC
                 fdatasync(fileno(fp));
+#else
+                fsync(fileno(fp));
+#endif
         }
         
         /* substract the time we needed for creating and saving
