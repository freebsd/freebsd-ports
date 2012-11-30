--- src/dvipdfmx.c.orig	2011-03-08 11:08:35.000000000 +0900
+++ src/dvipdfmx.c	2012-07-11 18:05:25.000000000 +0900
@@ -842,6 +842,9 @@
     if (!(STRCMP_BASE("dvipdfm") && STRCMP_BASE("ebb")))
       compat_mode = 1;
 
+    if (STRCMP_BASE("ebb-dvipdfmx") == 0)
+      return extractbb(argc, argv);
+
     if (!(STRCMP_BASE("extractbb") && STRCMP_BASE("xbb") &&
 	  STRCMP_BASE("ebb")))
       return extractbb(argc, argv);
