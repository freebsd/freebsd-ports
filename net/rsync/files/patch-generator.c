#
# fix --read-batch
#  <http://lists.samba.org/archive/rsync/2004-May/009404.html>
#
--- generator.c.orig	Thu Apr 15 18:55:23 2004
+++ generator.c	Wed May 12 13:55:13 2004
@@ -46,6 +46,7 @@
 extern int whole_file;
 extern int local_server;
 extern int write_batch;
+extern int read_batch;
 extern int list_only;
 extern int only_existing;
 extern int orig_umask;
@@ -213,7 +214,7 @@
 {
 	if (whole_file > 0)
 		return True;
-	if (whole_file == 0 || write_batch)
+	if (whole_file == 0 || write_batch || read_batch)
 		return False;
 	return local_server;
 }
