--- config-top.h.orig	2016-05-19 18:34:02 UTC
+++ config-top.h
@@ -74,7 +74,7 @@
 #endif
 
 /* Default primary and secondary prompt strings. */
-#define PPROMPT "\\s-\\v\\$ "
+#define PPROMPT "[\\u@\\h \\w]\\$ "
 #define SPROMPT "> "
 
 /* Undefine this if you don't want the ksh-compatible behavior of reprinting
