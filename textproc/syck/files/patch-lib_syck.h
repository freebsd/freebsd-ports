--- lib/syck.h.orig	2013-03-14 21:32:03.000000000 +0800
+++ lib/syck.h	2013-03-14 21:32:45.000000000 +0800
@@ -467,7 +467,7 @@
 /*
  * Lexer prototypes
  */
-void syckerror( const char * );
+void syckerror( void *, const char * );
 int syckparse( void * );
 
 #if defined(__cplusplus)
