--- clamav-milter/clamav-milter.c.orig	Sun Feb  6 21:35:29 2005
+++ clamav-milter/clamav-milter.c	Wed Feb  9 10:00:06 2005
@@ -643,7 +643,7 @@
 
 #define	VERSION_LENGTH	128
 
-#define	SESSION	/*
+/* #define	SESSION
 		 * Keep one command connection open to clamd, otherwise a new
 		 * command connection is created for each new email
 		 *
