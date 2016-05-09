--- MString.cpp.orig	2000-06-22 14:58:41 UTC
+++ MString.cpp
@@ -1,6 +1,9 @@
 
 #include "MString.H"
 
+String Left(const String &, int);
+String Mid(String, int, int);
+String Right(const String &, int);
 
 // コンストラクタ
 String::String(int n)
