--- include/Ptr.cxx.orig	1998-10-07 05:15:50 UTC
+++ include/Ptr.cxx
@@ -19,7 +19,7 @@ template<class T>
 Ptr<T>::~Ptr()
 {
   if (ptr_) {
-    if (ptr_->unref())
+    if (((Resource*)ptr_)->unref())
       delete ptr_;
     ptr_ = 0;
   }
