--- ./sources/family.h.orig	Fri Aug  4 10:13:45 2000
+++ ./sources/family.h	Wed Aug 17 00:07:37 2005
@@ -85,7 +85,7 @@
 
     virtual ~Son() { }
 
-    void* operator new(size_t /*size*/)  { cout.flush(); abort();  return 0; }
+    void* operator new(size_t /*size*/) throw() { cout.flush(); abort();  return 0; }
     void  operator delete(void* /*son*/) { cout.flush(); abort(); }
 
     virtual int  NoOfFathers() const = 0;
