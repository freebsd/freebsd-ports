--- libMG/src/libMG.h	Thu Aug 12 10:34:49 2004
+++ libMG/src/libMG.h	Fri Aug 27 02:48:55 2004
@@ -307,7 +307,7 @@
 	{							\
 		errorCode	= 1;				\
 	}							\
-	strcpy( var, string );
+	strncpy( var, string, strlen(string)+1 );
 
 #include	<MGrFileSize.h>
 #include	<MGrFileTime.h>
