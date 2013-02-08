--- globals.h.orig	2007-04-09 00:51:09.000000000 -0700
+++ globals.h	2011-01-06 22:55:10.000000000 -0800
@@ -15,7 +15,9 @@
 #define VERSION "2.1"
 #define RCFILE ".asmailrc"
 /* Watch out! The MAX_INPUT_LENGTH must be a multiple of 64! */
-#define MAX_INPUT_LENGTH 255
+/* Why?? 255 (the original value) is not a multiple of 64. 255 is too small */
+/* for IMAP responses */
+#define MAX_INPUT_LENGTH 4096
 
 #define pthread_attr_default NULL
 
--- patch-globals.h ends here ---
