--- cxxlib.h.orig	Sun Nov  3 23:49:03 2002
+++ cxxlib.h	Wed Nov  6 09:41:36 2002
@@ -33,12 +33,14 @@
 // new/delete operators
 //
 
+#ifndef __FreeBSD__
 void *operator new (size_t s) CXX__NEW_THROW;
 void operator delete (void *p) CXX__DELETE_THROW;
 #ifdef CXX__HAVE_ARRAY_NEW
 void *operator new[] (size_t s) CXX__NEW_THROW;
 void operator delete[] (void *p) CXX__DELETE_THROW;
 #endif	/* CXX__HAVE_ARRAY_NEW */
+#endif
 
 //
 // string I/O stream
