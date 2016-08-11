--- MString.H.orig	2000-06-22 14:58:26 UTC
+++ MString.H
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
 
@@ -307,15 +308,15 @@ class String
 
     // m 文字目から n 文字
     String& Mid(int m, int n = 1) ;
-    friend String Mid(String s, int m, int n = 1) ;
+    friend String Mid(String s, int m, int n) ;
 
     // 左から n 文字
     String& Left(int n = 1) ;
-    friend String Left(const String& s, int n = 1) ;
+    friend String Left(const String& s, int n) ;
 
     // 右から n 文字
     String& Right(int n = 1) ;
-    friend String Right(const String& s, int n = 1) ;
+    friend String Right(const String& s, int n) ;
 
 	String FileDirectory() const ;
 	String FileNamePart() const ;
