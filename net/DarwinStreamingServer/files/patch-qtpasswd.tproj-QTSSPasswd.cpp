--- qtpasswd.tproj/QTSSPasswd.cpp.orig	2008-05-06 08:28:58.000000000 +0900
+++ qtpasswd.tproj/QTSSPasswd.cpp	2008-06-01 18:11:56.000000000 +0900
@@ -723,7 +723,7 @@
     extern int optind;
 
 	/* Read command line arguments */
-    while ((ch = getopt(argc, argv, "O:f:cg:r:p:P:A:D:C:R:dFhv?")) != EOF)
+    while ((ch = getopt(argc, argv, "O:f:cg:r:p:P:A:D:C:R:dFhv?")) != -1)
     {
         switch(ch) 
         {
