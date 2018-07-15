--- libddr_lzo.c.orig	2017-11-04 09:14:24 UTC
+++ libddr_lzo.c
@@ -46,6 +46,7 @@
 #error __WORDSIZE unknown
 #endif
 
+#define HAVE_BASENAME 1
 #ifdef HAVE_BASENAME
 //char* basename(char*);
 #else
