--- src/FXString.cpp.orig	2016-11-18 18:04:41 UTC
+++ src/FXString.cpp
@@ -2365,7 +2365,7 @@ FXString& FXString::vformat(const FXchar
 #else
     va_list ag;
 x:  va_copy(ag,args);
-    result=vsnprintf(str,length()+1,fmt,a);
+    result=vsnprintf(str,length()+1,fmt,ag);
     va_end(ag);
     if(result<0){ length(FXMAX(64,length()*2)); goto x; }
     if(length()<result){ length(result); goto x; }
