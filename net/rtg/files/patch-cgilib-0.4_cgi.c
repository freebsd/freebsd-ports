--- cgilib-0.4/cgi.c.orig	2003-09-25 15:21:06 UTC
+++ cgilib-0.4/cgi.c
@@ -33,9 +33,12 @@
 #ifdef HAVE_CTYPE_H
 # include <ctype.h>
 #endif
+/* Unnecessary on FreeBSD; malloc.h included in stdlib.h */
+/*
 #ifdef HAVE_MALLOC_H
 # include <malloc.h>
 #endif
+*/
 
 #include <cgi.h>
 
