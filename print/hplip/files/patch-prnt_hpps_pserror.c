--- prnt/hpps/pserror.c.orig	2023-06-02 08:02:35 UTC
+++ prnt/hpps/pserror.c
@@ -24,7 +24,7 @@ void message(int flags, char *format, ...)
 void message(int flags, char *format, ...)
 {
   va_list args ;
-  static column = 0 ;		/* current screen column for message wrap */
+  static int column = 0 ;	/* current screen column for message wrap */
   char msgbuf[MAX_MESSAGE] ;	/* buffer in which to put the message */
   char *bufptr = msgbuf ;	/* message buffer pointer */
 
