$NetBSD: patch-src_SmartPtr.hpp,v 1.1 2011/09/21 12:54:16 adam Exp $

Fix C++ syntax

--- src/SmartPtr.hpp.orig	2011-09-21 12:48:02.000000000 +0000
+++ src/SmartPtr.hpp
@@ -150,7 +150,7 @@ namespace suPHP {
     template<class T>
     const SmartPtr<T>& suPHP::SmartPtr<T>::operator=(
         const SmartPtr<T>& ref) {
-        this.reset(ref.ptr);
+        this->reset(ref.ptr);
         return *this;
     }
     
