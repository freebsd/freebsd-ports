--- mtpfs.c.orig	2016-12-15 23:55:52 UTC
+++ mtpfs.c
@@ -1774,7 +1774,7 @@ main (int argc, char *argv[])
 
   DBG ("Start fuse");
 
-  fuse_stat = fuse_main (argc, argv, &mtpfs_oper);
+  fuse_stat = fuse_main (argc, argv, &mtpfs_oper, NULL);
   DBG ("fuse_main returned %d\n", fuse_stat);
   return fuse_stat;
 }
