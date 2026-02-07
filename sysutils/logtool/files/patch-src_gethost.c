--- src/gethost.c.orig	2003-05-16 20:13:20 UTC
+++ src/gethost.c
@@ -21,6 +21,8 @@
 /* Yee ole includes (I put this all in one file for my sanity) */
 #include "includes.h"
 
+char lt_host[LSIZE];
+
 #ifndef NO_RESOLVER
 /* var's for gethostbyaddr() stuff      */
 extern int h_errno;
