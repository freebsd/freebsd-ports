--- config-top.h.orig	2024-10-24 18:14:21 UTC
+++ config-top.h
@@ -79,7 +79,7 @@
 #endif
 
 /* Default primary and secondary prompt strings. */
-#define PPROMPT "\\s-\\v\\$ "
+#define PPROMPT "[\\u@\\h \\w]\\$ "
 #define SPROMPT "> "
 
 /* Undefine this if you don't want the ksh-compatible behavior of reprinting
