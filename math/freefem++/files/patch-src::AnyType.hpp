--- ./src/AnyType.hpp.orig	Sat May 31 11:53:05 2003
+++ ./src/AnyType.hpp	Sun Feb 29 16:13:27 2004
@@ -5,7 +5,8 @@
 class basicForEachType;
 typedef const  basicForEachType * aType;
 
-typedef  unsigned char  AnyData[24]; 
+//typedef  unsigned char  AnyData[24]; 
+typedef  unsigned char  AnyData[2*(sizeof(void*)+2*sizeof(double))];
 
 extern map<const string,basicForEachType *> map_type;
 
