--- ./zzn.h.orig	2014-04-10 22:52:14.562766913 -0500
+++ ./zzn.h	2014-04-10 22:52:17.524768077 -0500
@@ -183,7 +183,7 @@
     friend ZZn getB(void);        // get B parameter of elliptic curve
 
     friend ZZn  sqrt(const ZZn&); // only works if modulus is prime
-    friend ZZn  luc( const ZZn&, const Big&, ZZn* b3=NULL);
+    friend ZZn  luc( const ZZn&, const Big&, ZZn* b3);
 
     big getzzn(void) const;
 
@@ -206,6 +206,7 @@
 extern ZZn getA(void);  
 extern ZZn getB(void);    
 extern ZZn one(void);
+extern ZZn  luc( const ZZn&, const Big&, ZZn* b3=NULL);
 
 #endif
 
