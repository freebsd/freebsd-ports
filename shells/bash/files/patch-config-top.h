--- config-top.h.orig	2021-11-05 14:11:12 UTC
+++ config-top.h	2024-08-01 09:10:04 UTC
@@ -84,7 +84,7 @@
 #endif
 
 /* Default primary and secondary prompt strings. */
-#define PPROMPT "\\s-\\v\\$ "
+#define PPROMPT "[\\u@\\h \\w]\\$ "
 #define SPROMPT "> "
 
 /* Undefine this if you don't want the ksh-compatible behavior of reprinting
