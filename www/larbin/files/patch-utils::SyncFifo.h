$FreeBSD$

--- utils/SyncFifo.h.orig	Sat Jun  8 21:29:43 2002
+++ utils/SyncFifo.h	Sat Jun  8 21:31:09 2002
@@ -45,7 +45,7 @@
 };
 
 template <class T>
-SyncFifo<T>::SyncFifo (uint size = std_size) {
+SyncFifo<T>::SyncFifo (uint size) {
   tab = new T*[size];
   this->size = size;
   in = 0;
