--- src/FXString.cpp.orig	2016-06-16 04:16:00 UTC
+++ src/FXString.cpp
@@ -2353,7 +2353,7 @@ FXString& FXString::vformat(const FXchar
     length(result);
     vsnprintf(str,length()+1,fmt,args);
 #elif defined(HAVE_VSNPRINTF)           // Have vsnprintf()
-#if (__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 1))
+#if (__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 1)) || defined(__FreeBSD__)
     va_list ag;
     va_copy(ag,args);
     result=vsnprintf(str,length(),fmt,ag);
@@ -2365,7 +2365,7 @@ FXString& FXString::vformat(const FXchar
 #else
     va_list ag;
 x:  va_copy(ag,args);
-    result=vsnprintf(str,length()+1,fmt,a);
+    result=vsnprintf(str,length()+1,fmt,ag);
     va_end(ag);
     if(result<0){ length(FXMAX(64,length()*2)); goto x; }
     if(length()<result){ length(result); goto x; }
