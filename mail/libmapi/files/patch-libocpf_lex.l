--- libocpf/lex.l.orig	2016-01-14 11:16:14.988281000 +0100
+++ libocpf/lex.l	2016-01-14 11:16:21.702227000 +0100
@@ -29,7 +29,6 @@
 #include "libocpf/lex.h"
 
 #define	YY_EXTRA_TYPE	struct ocpf_context *
-#define	YY_NO_UNPUT
 
 static void unterminated(struct ocpf_context *, const char *, unsigned int);
 
