--- spunk/check.cc.orig	Tue Jul 30 20:10:24 1996
+++ spunk/check.cc	Thu Dec 23 20:52:21 2004
@@ -50,9 +50,6 @@
 
 
 // The fail vector
-#ifdef __GNUC__
-volatile
-#endif
 void (*CheckFailed) (const char*, const char* Cond,
 		     int Code, const char* File, int Line) = _CheckFailed;
 
