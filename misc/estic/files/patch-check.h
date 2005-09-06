--- spunk/check.h.orig	Tue Jul 30 20:10:26 1996
+++ spunk/check.h	Thu Dec 23 20:54:22 2004
@@ -38,9 +38,6 @@
 
 
 extern
-#ifdef __GNUC__
-volatile
-#endif
 void (*CheckFailed) (const char* Msg, const char* Cond, int Code,
 			    const char* File, int Line);
 // Function pointer that is called from Check if the condition code is true.
Only in foo/spunk: check.o
