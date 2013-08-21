--- src/nrpe.c.orig	2013-07-10 21:18:24.000000000 +0000
+++ src/nrpe.c	2013-07-10 21:20:25.000000000 +0000
@@ -89,7 +89,9 @@
 int     use_src=FALSE; /* Define parameter for SRC option */
 
 
+#ifdef HAVE_SSL
 void complete_SSL_shutdown( SSL *);
+#endif
 
 
 int main(int argc, char **argv){
@@ -1673,6 +1675,7 @@
 	return OK;
         }
 
+#ifdef HAVE_SSL
 void complete_SSL_shutdown( SSL *ssl) {
 
 	/*  
@@ -1693,6 +1696,7 @@
 		if( SSL_shutdown( ssl)) break;
 	}
 }
+#endif
 
 /* bail if daemon is running as root */
 int check_privileges(void){
