--- include/trbatch.h.orig	Fri Dec 17 00:17:03 1993
+++ include/trbatch.h	Sun Oct  8 11:23:50 2006
@@ -23,12 +23,12 @@
 };
 
 /* imports from trbatch.c */
-extern struct batchfile *bfopen(), *bfisopen();
-extern statust bffkclose(), bfrealclose();
+extern struct batchfile *bfopen();
+extern statust bffkclose();
 extern int bfflush();
 /* imports from trbatcomm.c */
-extern statust bfclose(), bfrclose();
-extern struct batchfile *bfincache(), *fakebf();
+extern statust bfclose();
+extern struct batchfile *fakebf();
 
 extern struct batchfile batchfile[];	/* try to keep open always */
 #define lastbf &batchfile[NOPENBFS-1]
