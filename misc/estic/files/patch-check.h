--- spunk/check.h.orig	1996-11-07 17:06:46 UTC
+++ spunk/check.h
@@ -38,9 +38,6 @@ extern const char* _MsgCheckFailed;     
 
 
 extern
-#ifdef __GNUC__
-volatile
-#endif
 void (*CheckFailed) (const char* Msg, const char* Cond, int Code,
                             const char* File, int Line);
 // Function pointer that is called from Check if the condition code is true.
