--- par.c.orig	Fri Aug 17 12:11:42 2001
+++ par.c	Mon Jan  5 13:01:20 2004
@@ -1149,14 +1149,14 @@
 {
     fprintf(stderr,
     "usage:\n"
-    "par t dbfile                                                - list\n"
-    "par h dbfile                                                - header\n"
-    "par x dbfile [ioptions] [records ..]                        - extract\n"
-    "par c [hoptions] dbfile name type cid [ioptions] [files ..] - create\n"
-    "par u [hoptions] dbfile [ioptions] [updates ..]             - touch\n"
-    "par a [hoptions] dbfile [ioptions] [files ..]               - append\n"
-    "par d [hoptions] dbfile [doptions] [records ..]             - delete\n"
-    "par version                                                 - version\n"
+    "pdbar t dbfile                                                - list\n"
+    "pdbar h dbfile                                                - header\n"
+    "pdbar x dbfile [ioptions] [records ..]                        - extract\n"
+    "pdbar c [hoptions] dbfile name type cid [ioptions] [files ..] - create\n"
+    "pdbar u [hoptions] dbfile [ioptions] [updates ..]             - touch\n"
+    "pdbar a [hoptions] dbfile [ioptions] [files ..]               - append\n"
+    "pdbar d [hoptions] dbfile [doptions] [records ..]             - delete\n"
+    "pdbar version                                                 - version\n"
     "where dbfile is a pdb:\n"
     "ioptions = [-A appinfo] [-S sortinfo]\n"
     "doptions = [-A] [-S]\n"
