--- src/dvipdfmx.c.orig	2009-05-11 11:15:25.000000000 +0900
+++ src/dvipdfmx.c	2009-06-12 10:26:27.000000000 +0900
@@ -806,6 +806,9 @@
     if (!(strcmp(base, "dvipdfm") && strcmp(base, "ebb")))
       compat_mode = 1;
 
+    if (strcmp(base, "ebb-dvipdfmx") == 0)
+      return extractbb(argc, argv);
+
     if (!(strcmp(base, "extractbb") && strcmp(base, "xbb") &&
 	  strcmp(base, "ebb")))
       return extractbb(argc, argv);
