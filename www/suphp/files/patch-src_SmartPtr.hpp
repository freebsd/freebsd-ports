--- src/SmartPtr.hpp.orig	2007-03-13 14:17:02 UTC
+++ src/SmartPtr.hpp
@@ -150,7 +150,7 @@ namespace suPHP {
     template<class T>
     const SmartPtr<T>& suPHP::SmartPtr<T>::operator=(
         const SmartPtr<T>& ref) {
-        this.reset(ref.ptr);
+        this->reset(ref.ptr);
         return *this;
     }
     
