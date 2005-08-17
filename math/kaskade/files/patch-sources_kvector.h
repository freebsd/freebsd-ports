--- ./sources/kvector.h.orig	Fri Dec 10 15:20:04 1999
+++ ./sources/kvector.h	Tue Aug 16 22:39:18 2005
@@ -12,20 +12,21 @@
 
 //-------------------------------------------------------------------------
 
-#include <iostream.h>
-#include <stdlib.h>	
+#include <iostream>
+using namespace std;
+#include <stdlib.h>
 
 //----------------------------------------------------------------------------
 
 template<class T>
 
-class Vector							 
-{									 
-  public:	
-							 
-    T*  v;						 
+class Vector
+{
+  public:
+
+    T*  v;
     int l, h;
-    
+
     Vector(int l1, int h1)  { allocate(l1, h1); }
     Vector(int h1) 	    { allocate( 1, h1); }
     Vector()		    { allocate( 1,  1); }
