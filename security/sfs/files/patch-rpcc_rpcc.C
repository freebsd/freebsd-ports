--- rpcc/rpcc.C.orig	2002-11-17 16:42:10.000000000 -0500
+++ rpcc/rpcc.C	2007-09-15 17:04:18.000000000 -0400
@@ -151,8 +151,8 @@
   void (*fn) (str) = NULL;
   int len;
 
-  av.push_back (PATH_CPP);
-  av.push_back ("-DRPCC");
+  av.push_back (const_cast<char *> (PATH_CPP));
+  av.push_back (const_cast<char *> ("-DRPCC"));
   av.push_back (NULL);
 
   for (an = 1; an < argc; an++) {
@@ -196,13 +196,13 @@
 
   switch (mode) {
   case HEADER:
-    av[2] = "-DRPCC_H";
+    av[2] = const_cast<char *> ("-DRPCC_H");
     fn = genheader;
     if (!outfile)
       outfile = strbuf ("%.*sh", len - 1, basename);
     break;
   case CFILE:
-    av[2] = "-DRPCC_C";
+    av[2] = const_cast<char *> ("-DRPCC_C");
     fn = gencfile;
     if (!outfile)
       outfile = strbuf ("%.*sC", len - 1, basename);
