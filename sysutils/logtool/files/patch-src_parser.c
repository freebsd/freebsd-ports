--- src/parser.c.orig	2003-05-29 18:13:56 UTC
+++ src/parser.c
@@ -20,6 +20,8 @@
 
 #include "includes.h"
 
+st_event event;
+
 /* a parsing function to do a string replacement (sorta like sed w/o the extended syntax)	*/
 
 /* A function to do string replacement's (a bit like sed) */
