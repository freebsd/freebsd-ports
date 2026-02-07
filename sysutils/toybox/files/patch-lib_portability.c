--- lib/portability.c.orig	2024-04-09 01:50:07 UTC
+++ lib/portability.c
@@ -65,7 +65,7 @@ struct mtab_list *xgetmountlist(char *path)
   int i, count;
 
   if (path) error_exit("xgetmountlist");
-  if ((count = getmntinfo(&entries, 0)) == 0) perror_exit("getmntinfo");
+  if (!(count = getmntinfo(&entries, MNT_NOWAIT))) perror_exit("getmntinfo");
 
   // The "test" part of the loop is done before the first time through and
   // again after each "increment", so putting the actual load there avoids
