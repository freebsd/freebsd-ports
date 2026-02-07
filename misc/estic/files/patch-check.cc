--- spunk/check.cc.orig	1996-11-07 17:06:46 UTC
+++ spunk/check.cc
@@ -50,9 +50,6 @@ static void _CheckFailed (const char* Ms
 
 
 // The fail vector
-#ifdef __GNUC__
-volatile
-#endif
 void (*CheckFailed) (const char*, const char* Cond,
                      int Code, const char* File, int Line) = _CheckFailed;
 
