--- ./src/ipmishell.c.orig	2009-02-25 15:38:52.000000000 -0500
+++ ./src/ipmishell.c	2010-07-23 14:46:07.000000000 -0400
@@ -57,7 +57,6 @@
 #ifdef HAVE_READLINE
 
 /* avoid warnings errors due to non-ANSI type declarations in readline.h */
-#define _FUNCTION_DEF
 #define USE_VARARGS
 #define PREFER_STDARG
 
