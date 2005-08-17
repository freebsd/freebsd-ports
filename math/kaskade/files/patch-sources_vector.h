--- ./sources/vector.h.orig	Fri Dec 10 15:21:23 1999
+++ ./sources/vector.h	Tue Aug 16 22:04:53 2005
@@ -12,20 +12,20 @@
 
 //-------------------------------------------------------------------------
 
-#include <iostream.h>
-#include <stdlib.h>	
+#include <iostream>
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
