--- src/util/Error.cc.orig	Wed Jan 29 14:00:24 2003
+++ src/util/Error.cc	Wed Jan 29 14:14:15 2003
@@ -51,12 +51,12 @@
 {
 	const int msg_size = 4096 ;
 	char err_msg[msg_size] ;
-	char *result = strerror_r( error_number, err_msg, msg_size ) ;
+	int result = strerror_r( error_number, err_msg, msg_size ) ;
 	
-	if ( result == 0 )
+	if ( result != 0 )
 		return "unknown error" ;
 	else
-		return result ;
+		return err_msg ;
 }
 
 const char* CFileError::what( ) const throw( )
