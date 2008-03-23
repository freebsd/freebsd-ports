--- cupsppd.c.orig	2008-03-20 10:16:42.000000000 -0400
+++ cupsppd.c	2008-03-20 10:17:16.000000000 -0400
@@ -451,7 +451,7 @@
   return PyBool_FromLong (nondefaults_marked);
 }
 
-#ifdef __SVR4
+#if 1
 /*
  * A rudimentary emulation of getline() for systems that dont support it
  * natively.  Since this is used for PPD file reading, it assumes (possibly
