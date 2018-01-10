--- include/Ptr.cxx.orig	Tue Jul 22 09:20:15 2003
+++ include/Ptr.cxx	Tue Jul 22 09:20:42 2003
@@ -19,7 +19,7 @@
 Ptr<T>::~Ptr()
 {
   if (ptr_) {
-    if (ptr_->unref())
+    if (((Resource*)ptr_)->unref())
       delete ptr_;
     ptr_ = 0;
   }
