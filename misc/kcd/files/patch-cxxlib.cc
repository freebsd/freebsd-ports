--- cxxlib.cc.orig	Sun Nov  3 23:49:03 2002
+++ cxxlib.cc	Wed Nov  6 09:42:38 2002
@@ -48,6 +48,7 @@
 	abort();
 }
 
+#ifndef __FreeBSD__
 void *operator new (size_t size) CXX__NEW_THROW
 {
 #ifdef LARGE_MEMORY_THRES
@@ -101,6 +102,7 @@
 }
 
 #endif	/* CXX__HAVE_ARRAY_NEW */
+#endif
 
 #ifndef CXX__NEW_THROW_BAD_ALLOC
 void	kcd_new_handler()
