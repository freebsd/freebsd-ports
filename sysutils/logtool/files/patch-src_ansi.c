--- src/ansi.c.orig	2003-04-21 17:42:38 UTC
+++ src/ansi.c
@@ -20,6 +20,8 @@
 
 #include "includes.h"
 
+st_color color;
+
 void lt_colorset_ansi() { /* this sets up color definitions for the output module */
 	
 	/* simple strcpy's to the appropriate variables			*/
