--- async/malloc.C.orig	Thu Jul 11 21:33:30 2002
+++ async/malloc.C	Thu Jul 11 21:32:22 2002
@@ -136,13 +136,13 @@
 
 
 void
-operator delete (void *ptr)
+operator delete (void *ptr) throw ()
 {
   xfree (ptr);
 }
 
 void
-operator delete[] (void *ptr)
+operator delete[] (void *ptr) throw ()
 {
   xfree (ptr);
 }
