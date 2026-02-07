--- src/includes/Ref.h.orig	2013-12-07 13:41:33.000000000 -0500
+++ src/includes/Ref.h	2013-12-07 13:41:49.000000000 -0500
@@ -189,7 +189,7 @@
 
   CRef<T> &operator=(const CRef<T> &other)
   {
-    assign(other);
+    this->assign(other);
     return *this;
   }
 
@@ -245,7 +245,7 @@
 
   Ref<T> &operator=(const Ref<T> &other)
   {
-    assign(other);
+    this->assign(other);
     return *this;
   }
 
