--- src/FXString.cpp.orig	2018-01-17 00:37:42 UTC
+++ src/FXString.cpp
@@ -2353,7 +2353,7 @@ FXString& FXString::vformat(const FXchar* fmt,va_list 
     length(result);
     vsnprintf(str,length()+1,fmt,args);
 #elif defined(HAVE_VSNPRINTF)           // Have vsnprintf()
-#if (__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 1))
+#if (__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 1)) || defined(__FreeBSD__)
     va_list ag;
     va_copy(ag,args);
     result=vsnprintf(str,empty()?0:length()+1,fmt,ag);
