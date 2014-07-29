--- src/ustr.cpp.orig	Thu Jan  6 13:21:40 2005
+++ src/ustr.cpp	Thu Jan  6 13:20:44 2005
@@ -297,7 +297,7 @@
 }
 
 Str &Str::Upper(void) {
-   for (int i = 0; i < Len; i++) {
+   for (unsigned int i = 0; i < Len; i++) {
       Ptr[i] = toupper(Ptr[i]);
    }
    return *this;
