--- http-gw/error.c.orig	Tue Jan 13 20:21:28 1998
+++ http-gw/error.c	Sun May 21 22:09:19 2006
@@ -174,11 +174,7 @@
 	return 0;
 }
 
-int go_error(sockfd, errorno, msg, va_alist)
-int sockfd;
-int errorno;
-char *msg;
-va_dcl
+int go_error(int sockfd, int errorno, char *msg, ...)
 {	static int last_errno = 0;
 	va_list marker;
 
@@ -192,7 +188,7 @@
 		}
 	}
 	if( msg != NULL){
-		va_start(marker);
+		va_start(marker, msg);
 		vsprintf(errbuf, msg, marker);
 		va_end(marker);
 		if( (rem_type & (TYPE_HTTP|TYPE_DIR)) == (TYPE_DIR)){
