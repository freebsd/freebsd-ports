--- src/proxy.c.orig	2015-09-01 18:49:36 UTC
+++ src/proxy.c
@@ -119,7 +119,7 @@ char * proxy_stringtable[] = {
 	"<body><h2>503 Service Unavailable</h2><h3>Your request violates configured policy</h3></body></html>\r\n",
 
 /* 16*/	"HTTP/1.0 401 Authentication Required\r\n"
-	"Proxy-Authenticate: basic realm=\"FTP Server\"\r\n"
+	"WWW-Authenticate: basic realm=\"FTP Server\"\r\n"
 	"Proxy-Connection: close\r\n"
 	"Content-type: text/html; charset=us-ascii\r\n"
 	"\r\n"
@@ -464,7 +464,7 @@ for(;;){
 		}
 		if(se)*se = '\r';
 	}
-	if(ftp && i > 19 && (!strncasecmp((char *)(buf+inbuf), "authorization", 19))){
+	if(ftp && i > 13 && (!strncasecmp((char *)(buf+inbuf), "authorization", 13))){
 		sb = (unsigned char *)strchr((char *)(buf+inbuf), ':');
 		if(!sb)continue;
 		++sb;
