--- pserror.c.orig	2011-06-21 04:20:14.000000000 +0900
+++ pserror.c	2011-06-21 04:20:31.000000000 +0900
@@ -24,7 +24,7 @@
 void message(int flags, char *format, ...)
 {
   va_list args ;
-  static column = 0 ;		/* current screen column for message wrap */
+  static int column = 0 ;		/* current screen column for message wrap */
   char msgbuf[MAX_MESSAGE] ;	/* buffer in which to put the message */
   char *bufptr = msgbuf ;	/* message buffer pointer */
 
