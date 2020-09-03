--- bc/global.h.orig	2017-04-07 22:20:02 UTC
+++ bc/global.h
@@ -112,9 +112,9 @@ EXTERN int n_history;
 
 #if defined(LIBEDIT)
 /* LIBEDIT data */
-EditLine *edit INIT(NULL);
-History  *hist;
-HistEvent histev;
+EXTERN EditLine *edit INIT(NULL);
+EXTERN History  *hist;
+EXTERN HistEvent histev;
 #endif
 
 /* "Condition code" -- false (0) or true (1) */
