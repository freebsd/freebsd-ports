--- reader.cc.orig	Thu Oct  8 03:12:09 1998
+++ reader.cc	Wed Mar 31 21:00:36 2004
@@ -18,7 +18,8 @@
 #endif /* HAVE_ALLOCA_H */
 #endif /* __GNUC__ */
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #ifdef HAVE_STRING_H
 #include <string.h>
@@ -40,7 +41,7 @@
 /* Please be aware that the junk should be stripped from in */
 static int read_character(istream *in)
 {
-    unsigned char c,d;
+    char c,d;
     static int s_ch=-1;
 
     if (s_ch==-1)
