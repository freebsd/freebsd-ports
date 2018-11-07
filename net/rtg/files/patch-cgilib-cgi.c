--- cgilib-0.4/cgi.c.orig	Thu Sep 25 08:21:06 2003
+++ cgilib-0.4/cgi.c	Sat May 14 01:28:33 2005
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
 
