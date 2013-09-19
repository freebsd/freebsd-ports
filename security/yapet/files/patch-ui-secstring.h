--- ui/secstring.h.orig	2013-09-18 19:44:08.000000000 +0200
+++ ui/secstring.h	2013-09-18 19:44:30.000000000 +0200
@@ -61,7 +61,7 @@
             public:
                 void deallocate (typename std::allocator<T>::pointer p,
                                  typename std::allocator<T>::size_type n) {
-                    memset (p, '0', n*sizeof (std::allocator<T>::value_type) );
+                    memset (p, '0', n*sizeof (typename std::allocator<T>::value_type) );
                     std::allocator<T>::deallocate (p, n);
                 }
 
