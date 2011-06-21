--- main.c.orig	1995-08-04 21:09:21.000000000 +0200
+++ main.c	2011-06-21 13:38:25.000000000 +0200
@@ -164,7 +164,7 @@
  *--------------------------------------------------------------
  */
 
-void
+int
 main(argc, argv)
      int argc;
      char **argv;
@@ -534,6 +534,7 @@
 
   realTimeStart = ReadSysClock();
   mpegVidRsrc(0, theStream);
+  return (0);
 }
  
 
