--- cxx/netcdfcpp.h.orig	Mon Sep 16 16:25:44 2002
+++ cxx/netcdfcpp.h	Mon Sep 16 16:26:23 2002
@@ -154,7 +154,7 @@
     virtual ~NcDim( void );
     
     // to construct dimensions, since constructor is private
-    friend NcFile;
+    friend class NcFile;
 };
 
 
@@ -357,7 +357,7 @@
     void init_cur( void );
 
     // to make variables, since constructor is private
-  friend NcFile;
+  friend class NcFile;
 };
 
 
@@ -388,7 +388,7 @@
     NcAtt( NcFile*, NcToken); // global attribute
     
     // To make attributes, since constructor is private
-  friend NcFile;
+  friend class NcFile;
   friend NcAtt* NcVar::get_att( NcToken ) const;
 };
 
