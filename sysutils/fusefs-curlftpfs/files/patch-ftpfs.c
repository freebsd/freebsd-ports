--- ./ftpfs.c.orig	2008-04-30 01:05:47.000000000 +0200
+++ ./ftpfs.c	2010-01-08 19:14:39.000000000 +0100
@@ -611,10 +611,12 @@
     curl_easy_cleanup(fh->write_conn);
   g_free(fh->full_path);
   g_free(fh->open_path);
-  sem_destroy(&fh->data_avail);
-  sem_destroy(&fh->data_need);
-  sem_destroy(&fh->data_written);
-  sem_destroy(&fh->ready);
+  if (fh->data_avail) {
+    sem_destroy(&fh->data_avail);
+    sem_destroy(&fh->data_need);
+    sem_destroy(&fh->data_written);
+    sem_destroy(&fh->ready);
+  }
   free(fh);
 }
 
