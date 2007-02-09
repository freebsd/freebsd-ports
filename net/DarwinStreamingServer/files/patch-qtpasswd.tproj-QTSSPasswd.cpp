--- qtpasswd.tproj/QTSSPasswd.cpp.orig	Fri May 20 04:03:22 2005
+++ qtpasswd.tproj/QTSSPasswd.cpp	Sat Feb 10 04:05:38 2007
@@ -720,7 +720,7 @@
     extern int optind;
 
 	/* Read command line arguments */
-    while ((ch = getopt(argc, argv, "O:f:cg:r:p:P:A:D:C:R:dFhv?")) != EOF)
+    while ((ch = getopt(argc, argv, "O:f:cg:r:p:P:A:D:C:R:dFhv?")) != -1)
     {
         switch(ch) 
         {
