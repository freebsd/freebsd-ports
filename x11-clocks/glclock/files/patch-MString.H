--- MString.H.orig	Thu Jun 22 16:58:26 2000
+++ MString.H	Sun Oct  1 22:32:31 2006
@@ -66,7 +66,7 @@
 #ifndef ___STRING_H___
 #define ___STRING_H___
 
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -75,6 +75,7 @@
 
 #include "Define.H"
 
+using namespace std;
 
 //#define STRING_DEBUG
 
@@ -407,6 +408,10 @@
     friend String& Cut(String      s) ;
     friend String& Cut(const char *s) ;
 } ;
+
+String Mid(String, int, int) ;
+String Left(const String&, int) ;
+String Right(const String&, int) ;
 
 // 整数から String へ
 String IntToString(int i) ;
