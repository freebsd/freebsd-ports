--- magicfilter.c.orig	Sat Oct 25 09:35:12 2003
+++ magicfilter.c	Sat Oct 25 09:36:48 2003
@@ -59,10 +59,10 @@
 /* Header of mail message */
 #ifndef NOMAIL
 const char *mailheader =	/* Header of complaint message */
-"To: %s\n\
-Subject: Rejected print job\n\
-
-Your print job was automatically rejected as an invalid data type.\n\n";
+"To: %s\n"
+"Subject: Rejected print job\n"
+"\n"
+"Your print job was automatically rejected as an invalid data type.\n\n";
 #endif
 
 /* ------------------------------------------------------------------------- *
