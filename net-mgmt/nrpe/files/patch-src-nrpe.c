--- src/nrpe.c.orig	2013-09-06 15:27:13 UTC
+++ src/nrpe.c
@@ -30,6 +30,8 @@
 #include "utils.h"
 #include "acl.h"
 
+#include <poll.h>
+
 #ifdef HAVE_SSL
 #include "../include/dh.h"
 #endif
@@ -100,7 +102,9 @@
 int     use_src=FALSE; /* Define parameter for SRC option */
 
 
+#ifdef HAVE_SSL
 void complete_SSL_shutdown( SSL *);
+#endif
 
 
 int main(int argc, char **argv){
@@ -266,7 +270,7 @@ int main(int argc, char **argv){
 
 		/* use anonymous DH ciphers */
 		SSL_CTX_set_cipher_list(ctx,"ADH");
-		dh=get_dh512();
+		dh=get_dh2048();
 		SSL_CTX_set_tmp_dh(ctx,dh);
 		DH_free(dh);
 		if(debug==TRUE)
@@ -969,8 +973,14 @@
 					continue;
 
 				/* socket is nonblocking and we don't have a connection yet */
-				if(errno==EAGAIN)
+				if(errno==EAGAIN) {
+					struct pollfd pfd;
+
+					pfd.fd = sock;
+					pfd.events = POLLIN;
+					poll(&pfd,1,-1);
 					continue;
+					}
 
 				/* fix for HP-UX 11.0 - just retry */
 				if(errno==ENOBUFS)
@@ -1207,9 +1217,13 @@
 	if(result==STATE_OK && use_ssl==TRUE){
 		if((ssl=SSL_new(ctx))!=NULL){
 			SSL_set_fd(ssl,sock);
+			int n = 0;
 
 			/* keep attempting the request if needed */
-                        while(((rc=SSL_accept(ssl))!=1) && (SSL_get_error(ssl,rc)==SSL_ERROR_WANT_READ));
+                        while( ((rc=SSL_accept(ssl))!=1) && (SSL_get_error(ssl,rc)==SSL_ERROR_WANT_READ) && n <= 600){
+				usleep(100000);
+				n++;
+			}
 
 			if(rc!=1){
 				syslog(LOG_ERR,"Error: Could not complete SSL handshake. %d\n",SSL_get_error(ssl,rc));
@@ -1796,6 +1810,7 @@
 	return OK;
         }
 
+#ifdef HAVE_SSL
 void complete_SSL_shutdown( SSL *ssl) {
 
 	/*  
@@ -1816,6 +1831,7 @@
 		if( SSL_shutdown( ssl)) break;
 	}
 }
+#endif
 
 /* bail if daemon is running as root */
 int check_privileges(void){
