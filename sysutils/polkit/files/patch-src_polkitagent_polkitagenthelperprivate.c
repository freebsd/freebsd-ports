--- src/polkitagent/polkitagenthelperprivate.c.orig	2011-02-23 18:18:11.000000000 +0000
+++ src/polkitagent/polkitagenthelperprivate.c	2011-02-23 18:18:41.000000000 +0000
@@ -103,7 +103,7 @@ flush_and_wait ()
 {
   fflush (stdout);
   fflush (stderr);
-  fdatasync (fileno(stdout));
-  fdatasync (fileno(stderr));
+  fsync (fileno(stdout));
+  fsync (fileno(stderr));
   usleep (100 * 1000);
 }
